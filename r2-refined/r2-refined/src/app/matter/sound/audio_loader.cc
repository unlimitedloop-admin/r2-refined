/**************************************************************/
//
//
//      Copyright (c) 2023 UNLIMITED LOOP ROOT-ONE
//
//
//      This software(and source code) is completely Unlicense.
//      see "LICENSE.md".
//
//
/**************************************************************/
//
//
//      r2-refined project
//
//      File name       : audio_loader.cc
//
//      Author          : u7
//
//      Last update     : 2023/04/03
//
//      File version    : 2
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * Implement a class that reads and uses sound data.
**/



/* INCLUDES */
// PRIMARY HEADER
#include "audio_loader.h"
// C++ SYSTEM HEADER
#include <cstdint>
#include <string>
// GENERAL USING HEADER
#include <DxLib.h>
// PROJECT USING HEADER
#include "src/protocol/process_code_hard.h"
#include "src/exceptions/exception_handler.h"
#include "src/app/matter/structures/tag_track_channel_p.h"
#include "src/database/tables/MST_APU_CHANNELS.h"
#include "src/database/tables/TRN_APU_CHANNEL_ENABLED.h"



/* SOURCES */
namespace matter {

    namespace sound {

        AudioLoader::AudioLoader(const uint8_t size, const LPTrackChannelParam files) : Loader(size) {
            std::wstring* ref = &files->square1;
            for (auto i = 0; i < size; ++i) {
                this->setFile(*(ref + i), i);
            }
        }


        AudioLoader::~AudioLoader() {
            for (auto& v : tunes_) {
                if (-1 == DxLib::DeleteSoundMem(v)) { setStaticProcessCode(0x00EAB1ULL, STATIC_ERR_DOMINATOR); }
            }
            tunes_.clear();
            tunes_.shrink_to_fit();
        }


        bool AudioLoader::Unzip(const uint8_t channels) {
            if (32U <= channels) {
                NATIVE_MSG(L"#Exception_desc: channels => %d", channels);
                setStaticProcessCode(0x00E9F1ULL, STATIC_ERR_DOMINATOR);
                return false;
            }
            tunes_.resize(static_cast<size_t>(DB::TRN_APU_CHANNEL_ENABLED::Select()));
            louder_.resize(static_cast<size_t>(DB::TRN_APU_CHANNEL_ENABLED::Select()));
            uint16_t index = 0;
            for (const auto& e : array_list_) {
                index = &e - &array_list_[0];
                if ((channels & e) && !this->getFile(index).empty()) {
                    if (tunes_[index] = DxLib::LoadSoundMem(this->getFile(index).c_str()); -1 == tunes_[index]) {
                        setStaticProcessCode(0x00EBF1ULL, STATIC_ERR_DOMINATOR);
                        return false;
                    }
                    louder_[index] = 100;   // TODO : It's a magic number! :(
                }
            }
        }


        bool AudioLoader::Play(const uint8_t channel, const bool rewind) const {
            if (16U < channel) {
                NATIVE_MSG(L"#Exception_desc: channels => %d", channel);
                setStaticProcessCode(0x00E9F1ULL, STATIC_ERR_DOMINATOR);
                return false;
            }
            const int track = tunes_[channel];
            if (!rewind && (-1 == DxLib::CheckSoundMem(track))) { return false; }
            else if (!rewind && DxLib::CheckSoundMem(track)) { return true; }       // If cueing is invalid and the music is still being played, the process ends without playing sound.
            // ...else rewind is true or rewind is false and no sound.
            
            if (-1 == DxLib::StopSoundMem(track)) { return false; }
            if (-1 == DxLib::PlaySoundMem(track, DX_PLAYTYPE_BACK, TRUE)) { return false; }
            return true;
        }


        bool AudioLoader::Stop(const uint8_t channels) const {
            if (32U <= channels) {
                NATIVE_MSG(L"#Exception_desc: channels => %d", channels);
                setStaticProcessCode(0x00E9F1ULL, STATIC_ERR_DOMINATOR);
                return false;
            }
            uint16_t index = 0;
            for (const auto& e : array_list_) {
                index = &e - &array_list_[0];
                if ((channels & e) && !this->getFile(index).empty() && (1 == DxLib::CheckSoundMem(tunes_[index]))) {
                    if (-1 == DxLib::StopSoundMem(tunes_[index])) { return false; }
                }
            }
            return true;
        }


        bool AudioLoader::Del(const uint8_t channels) const {
            if (32U <= channels) {
                NATIVE_MSG(L"#Exception_desc: channels => %d", channels);
                setStaticProcessCode(0x00E9F1ULL, STATIC_ERR_DOMINATOR);
                return false;
            }
            uint16_t index = 0;
            for (const auto& e : array_list_) {
                index = &e - &array_list_[0];
                if ((channels & e) && !this->getFile(index).empty()) {
                    (void)DxLib::DeleteSoundMem(tunes_[index]);
                }
            }
            return true;
        }


        bool AudioLoader::changeVolume(const size_t channel, const size_t volume) {
            if (16U < channel) {
                NATIVE_MSG(L"#Exception_desc: channels => %d", channel);
                setStaticProcessCode(0x00E9F1ULL, STATIC_ERR_DOMINATOR);
                return false;
            }
            louder_[channel] = 255.00 * volume / 100;   // TODO : It's a magic number! :(
            if (-1 == DxLib::ChangeVolumeSoundMem(louder_[channel], tunes_[channel])) { return false; }
            return true;
        }


        // HACK : This method will be deleted. The score settings shouldn't be changed while the application is running, they are configuration settings and should be normalized by the database.
        bool AudioLoader::setMusicNotation(const uint8_t channel, const size_t start_point, const size_t end_point, const size_t DS_point) {
            if (16U < channel) {
                NATIVE_MSG(L"#Exception_desc: channels => %d", channel);
                setStaticProcessCode(0x00E9F1ULL, STATIC_ERR_DOMINATOR);
                return false;
            }
            const int track = tunes_[channel];
            if (-1 == DxLib::SetSoundCurrentTime(start_point, track)) { return false; }         // Sets the playback position of the sound handle in milliseconds.
            if (-1 == DxLib::SetLoopTimePosSoundMem(end_point, track)) { return false; }        // Set loop position in sound handle in milliseconds.
            if (-1 == DxLib::SetLoopStartTimePosSoundMem(DS_point, track)) { return false; }    // Sets the loop start position in the sound handle in milliseconds.
            return true;
        }


        bool AudioLoader::checkNowPlaying(const uint8_t channels) const {
            if (32U <= channels) {
                NATIVE_MSG(L"#Exception_desc: channels => %d", channels);
                setStaticProcessCode(0x00E9F1ULL, STATIC_ERR_DOMINATOR);
                return false;
            }
            uint16_t index = 0;
            for (const auto& e : array_list_) {
                index = &e - &array_list_[0];
                if ((channels & e) && !this->getFile(index).empty() && (1 == DxLib::CheckSoundMem(tunes_[index]))) {
                    return true;
                }
            }
            return false;
        }

    }  // namespace sound

}  // namespace matter