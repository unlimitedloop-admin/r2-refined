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
//      File name       : proof_stage_main.h
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
 * proof stage main.header
**/



#ifndef _R2R_APP_COMPONENT_CX_C1_SAMPLE2_STATE_PROOF_STAGE_MAIN_H_
#define _R2R_APP_COMPONENT_CX_C1_SAMPLE2_STATE_PROOF_STAGE_MAIN_H_

/* INCLUDES */
// PRIMARY HEADER
#include "src/app/models/component_state.h"
// PROJECT USING HEADER
#include "src/app/models/component_state_context.h"
#include "src/app/matter/blending/dealer.h"



/* SOURCES */
namespace component {

    namespace C1_sample2 {

        namespace state {

            /* using namespace */
            using namespace models;



            /// <summary>
            /// Proof stage state.
            /// </summary>
            class ProofStageMainState final : public implements::IComponentState {

            private:
                matter::blending::Dealer* mat_;     // materials pointer

                bool Update(void);

                bool Draw(void);

            public:
                ProofStageMainState(matter::blending::Dealer* mat_impl);
                ~ProofStageMainState();

                bool doAction(implements::IComponentStateContext* context) override;

            };

        }  // namespace state

    }  // namespace C1_sample2

}  // namespace component

#endif // !_R2R_APP_COMPONENT_CX_C1_SAMPLE2_STATE_PROOF_STAGE_MAIN_H_