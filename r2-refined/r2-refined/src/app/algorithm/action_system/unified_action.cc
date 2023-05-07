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
//      File name       : unified_action.cc
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
 * Integration of the "action system".
**/



/* INCLUDES */
// PRIMARY HEADER
#include "unified_action.h"
// PROJECT USING HEADER
#include "src/app/algorithm/action_system/BG/background_scrolling.h"
#include "src/app/algorithm/action_system/player/player_job.h"
#include "src/app/matter/blending/dealer.h"



/* SOURCES */
namespace algorithm {

    namespace action_system {

        UnifiedAction::UnifiedAction() {}


        UnifiedAction::~UnifiedAction() {}


        bool UnifiedAction::Work(matter::blending::Dealer* impl) {
            BG::BackgroundScrolling bg_obj;
            BG::RelativeDiffCoord bg_param = bg_obj.Adjust();
            for (size_t i = 0ui64; i < 4; ++i) {
                if (!bg_obj.flatMove(&bg_param, impl->BG.getVertex(i))) {
                    return false;
                }
            }
            return true;
        }

    }  // namespace action_system

}  // namespace algorithm