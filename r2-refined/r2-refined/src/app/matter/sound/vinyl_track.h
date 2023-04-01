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
//      File name       : vinyl_track.h
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
 * vinyl track.header
**/



#ifndef _R2R_APP_MATTER_VINYL_TRACK_H_
#define _R2R_APP_MATTER_VINYL_TRACK_H_

/* INCLUDES */
// PRIMARY HEADER
#include "vinyl.h"
// C++ SYSTEM HEADER
#include <string>
// PROJECT USING HEADER
#include "src/app/models/echo_benefits.h"
#include "src/app/matter/structures/tag_track_channel_p.h"



/* SOURCES */
namespace matter {

    namespace sound {

        /* using namespace */
        using namespace models;



        /// <summary>
        /// This is the master vinyl record that generates sound data.
        /// </summary>
        class VinylTrack : public extends::Vinyl {

        public:
            ~VinylTrack() {}
            
            /// <summary>
            /// Create track data.
            /// </summary>
            /// <param name="files">A set of file paths for the instrument sources to create</param>
            /// <returns>Sound data common interface object</returns>
            implements::IEchoBenefits* createTrack(const LPTrackChannelParam files) const override;

        };

    }  // namespace sound

}  // namespace matter

#endif // !_R2R_APP_MATTER_VINYL_TRACK_H_