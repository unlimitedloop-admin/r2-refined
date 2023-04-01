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
//      File name       : vinyl.h
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
 * Diecast for creating some object data.
**/



#ifndef _R2R_APP_MATTER_SOUND_VINYL_H_
#define _R2R_APP_MATTER_SOUND_VINYL_H_

/* INCLUDES */
// PROJECT USING HEADER
#include "src/app/models/echo_benefits.h"
#include "src/app/matter/structures/tag_track_channel_p.h"



/* SOURCES */
namespace matter {

    namespace sound {

        namespace extends {

            /* using namespace */
            using namespace models;



            /// <summary>
            /// Factory method class for creating sound data instances.
            /// </summary>
            class Vinyl {

            protected:
                virtual implements::IEchoBenefits* createTrack(const LPTrackChannelParam files) const = 0;

            public:
                virtual ~Vinyl() {}

                /// <summary>
                /// Factory class for creating sound data.
                /// </summary>
                /// <param name="files">File path of the sound data to get</param>
                /// <returns>Product of sound data</returns>
                virtual implements::IEchoBenefits* Create(const LPTrackChannelParam files) {
                    implements::IEchoBenefits* object = createTrack(files);
                    return object;
                }

            };

        }  // namespace extends

    }  // namespace sound

}  // namespace matter

#endif // !_R2R_APP_MATTER_SOUND_VINYL_H_