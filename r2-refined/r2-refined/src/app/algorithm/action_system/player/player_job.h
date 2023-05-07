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
//      File name       : player_job.h
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
 * player job.header
**/



#ifndef _R2R_APP_ALGORITHM_ACTION_SYSTEM_PLAYER_PLAYER_JOB_H_
#define _R2R_APP_ALGORITHM_ACTION_SYSTEM_PLAYER_PLAYER_JOB_H_

/* INCLUDES */
// PROJECT USING HEADER
#include "src/app/matter/structures/tag_axisation.h"
#include "src/app/algorithm/action_system/BG/background_scrolling.h"



/* SOURCES */
namespace algorithm {

    namespace action_system {

        namespace player {

            /// <summary>
            /// A class that does the work of the controlled character.
            /// </summary>
            class PlayerJob {

            public:
                PlayerJob() {}
                ~PlayerJob() {}

                /// <summary>
                /// Move the character.
                /// </summary>
                /// <param name="params">Object movement information pointer</param>
                /// <param name="points"></param>
                /// <returns>True if the operation was successful</returns>
                bool flatMove(const BG::LPRelativeDiffCoord params, matter::LPAxisation points) const;

            };

        }  // namespace player

    }  // namespace action_system

}  // namespace algorithm

#endif // !_R2R_APP_ALGORITHM_ACTION_SYSTEM_PLAYER_PLAYER_JOB_H_