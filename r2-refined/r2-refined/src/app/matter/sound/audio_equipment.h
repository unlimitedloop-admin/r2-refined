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
//      File name       : audio_equipment.h
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
 * audio equipment.header
**/



#ifndef _R2R_APP_MATTER_SOUND_AUDIO_EQUIPMENT_H_
#define _R2R_APP_MATTER_SOUND_AUDIO_EQUIPMENT_H_

/* INCLUDES */
// C++ SYSTEM HEADER
#include <string>
#include <vector>
#include <map>
// PROJECT USING HEADER
#include "src/app/models/echo_benefits.h"
#include "src/app/matter/structures/tag_track_channel_p.h"



/* SOURCES */
namespace matter {

    namespace sound {

        /* using namespace */
        using namespace models;



        /// <summary>
        /// Management of some sound data source.
        /// </summary>
        class AudioEquipment {

        private:
            /// <summary>
            /// Sound data sources.
            /// </summary>
            std::map<std::string, implements::IEchoBenefits*> objects_;

        public:
            AudioEquipment();
            AudioEquipment(const AudioEquipment& cc);
            ~AudioEquipment();

            /// <summary>
            /// Load sound source data into memory.
            /// </summary>
            /// <param name="name">Track names</param>
            /// <param name="filepath">File path of the sound data to get</param>
            /// <returns>True if loaded into memory successfully, false otherwise</returns>
            bool Push(const std::string name, const LPTrackChannelParam filepath);

            /// <summary>
            /// Ring a sound source data into memory.
            /// </summary>
            /// <param name="name">Track names</param>
            /// <param name="channel">Target channel</param>
            /// <param name="volume">Volume of ring a sound</param>
            /// <param name="cue">Specify true to rewind</param>
            /// <returns>True if ringing into memory successfully, false otherwise</returns>
            bool Ring(const std::string name, const uint8_t channel, const size_t volume, bool cue) const;

            /// <summary>
            /// Plays the specified sound data on all channels.
            /// </summary>
            /// <param name="name">Track names</param>
            /// <param name="volume">Volume of ring a sound</param>
            /// <param name="cue">Specify true to rewind</param>
            /// <returns>True if ringing into memory successfully, false otherwise</returns>
            bool allChannelGo(const std::string name) const;

            /// <summary>
            /// Stops the sound source that is playing.
            /// </summary>
            /// <param name="name">Track names</param>
            /// <returns>True if stoped ring a sound successfully</returns>
            bool allChannelStop(const std::string name) const;

            /// <summary>
            /// Volume adjustment.
            /// </summary>
            /// <param name="name">Track names</param>
            /// <param name="channel">Target channel</param>
            /// <param name="volume">Change the volume value</param>
            /// <returns>True if changing in track volume of channel successfully, false otherwise</returns>
            bool volumeControl(const std::string name, const std::string channel, const size_t volume) const;

            /// <summary>
            /// Checks if the specified channel is sounding.
            /// </summary>
            /// <param name="name">Track names</param>
            /// <param name="channel">Check the playing sound data</param>
            /// <returns>True if playing a specified sound data, false stop sound</returns>
            bool checkNowPlaying(const std::string name) const;

            /// <summary>
            /// Get volume levels.
            /// </summary>
            /// <param name="name">Track names</param>
            /// <param name="channel">Target channel</param>
            /// <returns>Volumes</returns>
            uint8_t getVolume(const std::string name, const std::string channel) const;

            /// <summary>
            /// Stop the ringing sound for all.
            /// </summary>
            /// <param name="">Void</param>
            /// <returns>True if all sounds have stopped, false otherwise.</returns>
            bool allTrackStop(void) const;

        };

    }  // namespace sound

}  // namespace matter

#endif // !_R2R_APP_MATTER_SOUND_AUDIO_EQUIPMENT_H_