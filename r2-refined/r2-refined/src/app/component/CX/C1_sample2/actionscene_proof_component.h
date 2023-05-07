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
//      File name       : actionscene_proof_component.h
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
 * actionscene proof component.header
**/



#ifndef _R2R_APP_COMPONENT_CX_C1_SAMPLE2_ACTIONSCENE_PROOF_COMPONENT_H_
#define _R2R_APP_COMPONENT_CX_C1_SAMPLE2_ACTIONSCENE_PROOF_COMPONENT_H_

/* INCLUDES */
// PRIMARY HEADER
#include "src/app/models/components.h"
#include "src/app/models/component_state_context.h"
// PROJECT USING HEADER
#include "src/app/models/radar.h"
#include "src/app/models/component_state.h"
#include "src/protocol/evaluation.h"
#include "src/app/matter/blending/dealer.h"



/* SOURCES */
namespace component {

    namespace C1_sample2 {

        /* using namespace */
        using namespace protocol;
        using namespace models;



        /// <summary>
        /// A class that does a proof-of-concept for an action scene.
        /// </summary>
        class ActionsceneProofComponent : public implements::IComponents, public implements::IComponentStateContext {

        private:
            implements::IComponentState* phase_ = nullptr;
            Evaluate status_;
            matter::blending::Dealer* mat_;         // materials pointer

        public:
            ActionsceneProofComponent();
            ActionsceneProofComponent(const ActionsceneProofComponent&) = delete;
            ~ActionsceneProofComponent();

            bool doComponentScene(implements::IRadar* object) override;
            bool anomalyDetector(void) override;
            void setComponentState(implements::IComponentState* obj) override;

        };

    }  // namespace C1_sample2

}  // namespace component

#endif // !_R2R_APP_COMPONENT_CX_C1_SAMPLE2_ACTIONSCENE_PROOF_COMPONENT_H_