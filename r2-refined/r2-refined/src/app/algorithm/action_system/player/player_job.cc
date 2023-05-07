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
//      File name       : player_job.cc
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
 * Some implementations related to player operation.
**/



/* INCLUDES */
// PRIMARY HEADER
#include "player_job.h"
// PROJECT USING HEADER
#include "src/app/matter/structures/tag_axisation.h"
#include "src/app/algorithm/action_system/BG/background_scrolling.h"



/* SOURCES */
namespace algorithm {

    namespace action_system {

        namespace player {

            bool PlayerJob::flatMove(const BG::LPRelativeDiffCoord params, matter::LPAxisation points) const {
                if (params->up) {
                    points->SetY(points->GetY() - params->up);
                }
                else if (params->down) {
                    points->SetY(params->down + points->GetY());
                }
                else {}
                if (params->left) {
                    points->SetX(points->GetX() - params->left);
                }
                else if (params->right) {
                    points->SetX(params->right + points->GetX());
                }
                else {}
                return true;
            }

        }  // namespace player

    }  // namespace action_system

}  // namespace algorithm