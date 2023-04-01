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
//      File name       : audio_loader.h
//
//      Author          : u7
//
//      Last update     : 2023/04/01
//
//      File version    : 1
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * audio loader.header
**/



#ifndef _R2R_APP_MATTER_SOUND_AUDIO_LOADER_H_
#define _R2R_APP_MATTER_SOUND_AUDIO_LOADER_H_

/* INCLUDES */
// PRIMARY HEADER
#include "src/app/models/loader.h"
#include "src/app/models/echo_benefits.h"
// C++ SYSTEM HEADER
#include <cstdint>
#include <vector>
// PROJECT USING HEADER
#include "src/app/matter/structures/tag_track_channel_p.h"
#include "src/database/views/MST_APU_CHANNELS_VIEW.h"



/* SOURCES */
namespace matter {

    namespace sound {

        /// <summary>
        /// A loader that reads and manages audio's BGM and sound effect data.
        /// </summary>
        class AudioLoader : public models::extends::Loader, public models::implements::IEchoBenefits {

        private:
            /// <summary>
            /// Sound data handler.
            /// </summary>
            std::vector<int> tunes_;

            /// <summary>
            /// Sound volume level.
            /// </summary>
            std::vector<uint8_t> louder_;

            /// <summary>
            /// APU channel list.
            /// </summary>
            const std::vector<uint8_t> array_list_ = DB::APU_CHANNELS_VIEW::arrayList();

        public:
            AudioLoader(const uint8_t size, const LPTrackChannelParam files);
            ~AudioLoader();

            /// <summary>
            /// Loads a sound data for specified any channels.
            /// </summary>
            /// <param name="channels">Target channel (Multiple specification OK)</param>
            /// <returns>True if loaded into memory successfully, false otherwise</returns>
            bool Unzip(const uint8_t channels) override;

            /// <summary>
            /// Play a sound data for specified any channels.
            /// </summary>
            /// <param name="channel">Specify the solo channel of sound</param>
            /// <param name="rewind">True when playing back to the beginning</param>
            /// <returns>True if play the sound successfully, false otherwise</returns>
            bool Play(const uint8_t channel, const bool rewind) const override;

            /// <summary>
            /// Stop a sound data for specified any channels.
            /// </summary>
            /// <param name="channels">Target channel (Multiple specification OK)</param>
            /// <returns>True if stop the sound successfully, false otherwise</returns>
            bool Stop(const uint8_t channels) const override;

            /// <summary>
            /// Removed loaded sound source handle.
            /// </summary>
            /// <param name="channels">Target channel (Multiple specification OK)</param>
            /// <returns>True if loaded into memory successfully, false otherwise</returns>
            bool Del(const uint8_t channels) const override;

            /// <summary>
            /// Adjust a sound volume for specified any channels.
            /// </summary>
            /// <param name="channels">Target channel</param>
            /// <param name="volume">Turn volume output ratio</param>
            /// <returns>True if change the sound successfully, false otherwise</returns>
            bool changeVolume(const size_t channel, const size_t volume) override;

            /// <summary>
            /// Sets sound property information for the specified channel.
            /// </summary>
            /// <param name="start_point">Specifies the start point of the sound source in milliseconds</param>
            /// <param name="end_point">Specifies the loop point in milliseconds.</param>
            /// <param name="DS_point">Specifies the loop restart point [DalSegno symbol] in milliseconds.</param>
            /// <returns>True if setting the sound property successfully, false otherwise</returns>
            bool setMusicNotation(const uint8_t channel, const size_t start_point, const size_t end_point, const size_t DS_point) override;

            /// <summary>
            /// Checks if the specified channel is ringing of sound.
            /// </summary>
            /// <param name="channels">Target channel (Multiple specification OK)</param>
            /// <returns>True if playing a specified sound data, false stop sound</returns>
            bool checkNowPlaying(const uint8_t channels) const;

            /// <summary>
            /// Get sound data source, specified number.
            /// </summary>
            /// <param name="num">Target number</param>
            /// <returns>The value of tunes_ in member</returns>
            inline int getTunes(const size_t num) const {
                if (num < tunes_.size()) { return tunes_[num]; }
            }

            /// <summary>
            /// Get sound volume, specified number.
            /// </summary>
            /// <param name="num">Target number</param>
            /// <returns>The value of louder_ in member</returns>
            inline uint8_t getLouder(const size_t num) const {
                if (num < louder_.size()) { return louder_[num]; }
            }

        };

    }  // namespace sound

}  // namespace matter

#endif // !_R2R_APP_MATTER_SOUND_AUDIO_LOADER_H_