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
//      File name       : vinyl_track.cc
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
 * Diecast for creating some sound tracks.
**/



/* INCLUDES */
// PRIMARY HEADER
#include "vinyl_track.h"
// C++ SYSTEM HEADER
#include <string>
// PROJECT USING HEADER
#include "src/app/models/echo_benefits.h"
#include "src/app/matter/structures/tag_track_channel_p.h"
#include "audio_loader.h"
#include "src/database/tables/TRN_APU_CHANNEL_ENABLED.h"



/* SOURCES */
namespace matter {

    namespace sound {

        implements::IEchoBenefits* VinylTrack::createTrack(const LPTrackChannelParam files) const {
            AudioLoader* object = new AudioLoader(static_cast<uint8_t>(DB::TRN_APU_CHANNEL_ENABLED::Select()), files);
            return object;
        }

    }  // namespace sound

}  // namespace matter