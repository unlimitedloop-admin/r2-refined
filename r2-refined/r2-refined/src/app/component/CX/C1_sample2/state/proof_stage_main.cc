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
//      File name       : proof_stage_main.cc
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
 * Implemented a proof of concept action scene.
**/



/* INCLUDES */
// PRIMARY HEADER
#include "proof_stage_main.h"
// PROJECT USING HEADER
#include "src/database/tables/MST_NES_PALETTE.h"
#include "src/traceable/output_logs.h"
#include "src/app/input/inputkey.h"
#include "src/app/route/region/C1_sample2_component.h"
#include "src/app/models/component_state_context.h"
#include "src/app/algorithm/action_system/unified_action.h"



/* SOURCES */
namespace component {

    namespace C1_sample2 {

        namespace state {

            /* using namespace */
            using namespace traceable;
            using namespace DB;



            ProofStageMainState::ProofStageMainState(matter::blending::Dealer* mat_impl) {
                mat_ = mat_impl;
                (void)writeStatusLog(L"C1_sample2::ProofStageMainStateを開始します。");
                MST_NES_PALETTE::tr_0x00();
            }


            ProofStageMainState::~ProofStageMainState() {
                (void)writeStatusLog(L"C1_sample2::ProofStageMainStateを終了します。");
            }


            bool ProofStageMainState::Update(void) {
                using namespace algorithm::action_system;
                if (!UnifiedAction().Work(mat_)) {
                    return false;
                }
                return true;
            }


            bool ProofStageMainState::Draw(void) {
                if (!mat_->BG.mappingOn()) {
                    return false;
                }
                //if (!mat_->SPRITE.Draw(L"Rockman")) {
                //    return false;
                //}
                return true;
            }


            bool ProofStageMainState::doAction(implements::IComponentStateContext* context) {
                using namespace input;
                if (!this->Update() || !this->Draw()) {
                    return false;
                }

                if (1 == GetKey(JPBTN::START)) {
                    context->setComponentState(route::region::C1Sample2Component().getStates(this, mat_));
                }
                return true;
            }

        }  // namespace state

    }  // namespace C1_sample2

}  // namespace component