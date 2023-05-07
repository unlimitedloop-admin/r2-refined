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
//      File name       : background_scrolling.h
//
//      Author          : u7
//
//      Last update     : 2023/05/07
//
//      File version    : 1
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * background scrolling.header
**/



#ifndef _R2R_APP_ALGORITHM_ACTION_SYSTEM_BG_BACKGROUND_SCROLLING_H_
#define _R2R_APP_ALGORITHM_ACTION_SYSTEM_BG_BACKGROUND_SCROLLING_H_

/* INCLUDES */
// C++ SYSTEM HEADER
#include <cstdint>
// PROJECT USING HEADER
#include "src/app/matter/structures/tag_axisation.h"



/* SOURCES */
namespace algorithm {

    namespace action_system {

        namespace BG {

            /// <summary>
            /// Relative pan exponent.
            /// </summary>
            typedef struct tagRelativeDiffCoord {
                int16_t up;
                int16_t down;
                int16_t right;
                int16_t left;
            } RelativeDiffCoord, *LPRelativeDiffCoord;


            /// <summary>
            /// Jurisdiction class for screen scroll processing.
            /// </summary>
            class BackgroundScrolling {

            public:
                BackgroundScrolling() {}
                ~BackgroundScrolling() {}

                /// <summary>
                /// Adjustment relative pan exponents.
                /// </summary>
                /// <param name="">Void</param>
                /// <returns>Relative pan exponent structure</returns>
                RelativeDiffCoord Adjust(void);

                /// <summary>
                /// Scroll the screen based on the relative movement information.
                /// </summary>
                /// <param name="params">Object movement information pointer</param>
                /// <param name="vertex">Screen coordinate data operation pointer</param>
                /// <returns>True if the operation was successful</returns>
                bool flatMove(const LPRelativeDiffCoord params, matter::LPAxisation vertex);

            };

        }  // namespace BG

    }  // namespace action_system

}  // namespace algorithm

#endif // !_R2R_APP_ALGORITHM_ACTION_SYSTEM_BG_BACKGROUND_SCROLLING_H_