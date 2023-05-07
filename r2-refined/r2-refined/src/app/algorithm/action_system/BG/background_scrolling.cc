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
//      File name       : background_scrolling.cc
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
 * Implemented internal processing of background tiles.
**/



/* INCLUDES */
// PRIMARY HEADER
#include "background_scrolling.h"
// PROJECT USING HEADER
#include "src/app/input/inputkey.h"
#include "src/app/matter/structures/tag_axisation.h"



/* SOURCES */
namespace algorithm {

    namespace action_system {

        namespace BG {

            /* using namespace */
            using namespace input;



            RelativeDiffCoord BackgroundScrolling::Adjust(void) {
                RelativeDiffCoord mutable_val = { 0, 0, 0, 0 };
                if (GetKey(JPBTN::UP)) {
                    ++mutable_val.up;
                }
                else if (GetKey(JPBTN::DOWN)) {
                    ++mutable_val.down;
                }
                else {}
                if (GetKey(JPBTN::LEFT)) {
                    ++mutable_val.left;
                }
                else if (GetKey(JPBTN::RIGHT)) {
                    ++mutable_val.right;
                }
                else {}
                return mutable_val;
            }


            bool BackgroundScrolling::flatMove(const LPRelativeDiffCoord params, matter::LPAxisation vertex) {
                if (params->up) {
                    vertex->SetY(params->up + vertex->GetY());
                }
                else if (params->down) {
                    vertex->SetY(vertex->GetY() - params->down);
                }
                else {}
                if (params->left) {
                    vertex->SetX(params->left + vertex->GetX());
                }
                else if (params->right) {
                    vertex->SetX(vertex->GetX() - params->right);
                }
                else {}
                return true;
            }

        }  // namespace BG

    }  // namespace action_system

}  // namespace algorithm