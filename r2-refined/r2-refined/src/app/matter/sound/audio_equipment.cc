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
//      File name       : audio_equipment.cc
//
//      Author          : u7
//
//      Last update     : 2023/04/02
//
//      File version    : 2
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * Implement a class to create and manage sound source data.
**/



/* INCLUDES */
// PRIMARY HEADER
#include "audio_equipment.h"
// C++ SYSTEM HEADER
#include <string>
// PROJECT USING HEADER
#include "src/app/matter/sound/vinyl.h"
#include "src/app/matter/sound/vinyl_track.h"
#include "src/database/tables/TRN_APU_CHANNEL_ENABLED.h"
#include "src/database/tables/MST_APU_CHANNELS.h"
#include "src/database/views/MST_APU_CHANNELS_VIEW.h"



/* SOURCES */
namespace matter {

    namespace sound {

        AudioEquipment::AudioEquipment() {
            objects_ = {};
        }


        AudioEquipment::AudioEquipment(const AudioEquipment& cc) {
            objects_ = cc.objects_;
        }


        AudioEquipment::~AudioEquipment() {
            auto begin = objects_.begin(), end = objects_.end();
            for (auto& itr = begin; itr != end; itr++) {
                delete itr->second;
                itr->second = nullptr;
            }
        }


        bool AudioEquipment::Push(const std::string name, const LPTrackChannelParam filepath) {
            extends::Vinyl* factory = new VinylTrack();
            objects_[name] = factory->Create(filepath);
            if (!objects_[name]->Unzip(DB::APU_CHANNELS_VIEW::allApuChannel())) { return false; }
            delete factory;
            return true;
        }


        bool AudioEquipment::Ring(const std::string name, const uint8_t channel, const size_t volume, bool cue) const {
            if (auto itr = objects_.find(name); itr != end(objects_)) {
                return itr->second->Play(channel, cue);
            }
        }


        bool AudioEquipment::allChannelGo(const std::string name) const {
            if (auto itr = objects_.find(name); itr != end(objects_)) {
                size_t source = static_cast<size_t>(DB::TRN_APU_CHANNEL_ENABLED::Select());
                for (size_t i = 0; i < source; ++i) {
                    itr->second->Play(i, true);
                }
            }
            return true;
        }


        bool AudioEquipment::allChannelStop(const std::string name) const {
            if (auto itr = objects_.find(name); itr != end(objects_)) {
                size_t source = static_cast<size_t>(DB::TRN_APU_CHANNEL_ENABLED::Select());
                for (size_t i = 0; i < source; ++i) {
                    itr->second->Stop(DB::APU_CHANNELS_VIEW::allApuChannel());
                }
            }
            return true;
        }


        bool AudioEquipment::volumeControl(const std::string name, const std::string channel, const size_t volume) const {
            if (auto itr = objects_.find(name); itr != end(objects_)) {
                return itr->second->changeVolume(DB::APU_CHANNELS::Rows(channel), volume);
            }
            return true;
        }


        bool AudioEquipment::checkNowPlaying(const std::string name) const {
            if (auto itr = objects_.find(name); itr != end(objects_)) {
                return itr->second->checkNowPlaying(DB::APU_CHANNELS_VIEW::allApuChannel());
            }
        }


        uint8_t AudioEquipment::getVolume(const std::string name, const std::string channel) const {
            if (auto itr = objects_.find(name); itr != end(objects_)) {
                return itr->second->getLouder(DB::APU_CHANNELS::Rows(channel));
            }
        }


        bool AudioEquipment::allTrackStop(void) const {
            for (const auto& v : objects_) {
                v.second->Stop(DB::APU_CHANNELS_VIEW::allApuChannel());
            }
            return true;
        }

    }  // namespace sound

}  // namespace matter