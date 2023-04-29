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
//      File name       : actionscene_proof_component.cc
//
//      Author          : u7
//
//      Last update     : 2023/04/29
//
//      File version    : 1
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * Proof-of-concept of action system.
**/



/* INCLUDES */
// PRIMARY HEADER
#include "actionscene_proof_component.h"
// PROJECT USING HEADER
#include "src/protocol/evaluation.h"
#include "state/setup_instance.h"
#include "src/app/route/region/C1_sample2_component.h"



/* SOURCES */
namespace component {

    namespace C1_sample2 {

        /* using namespace */
        using namespace protocol;



        ActionsceneProofComponent::ActionsceneProofComponent() {
            status_ = Evaluate::PROC_SUCCEED;
            phase_ = route::region::C1Sample2Component().getStates(phase_);
        }


        ActionsceneProofComponent::~ActionsceneProofComponent() {
            if (nullptr != phase_) {
                delete phase_;
                phase_ = nullptr;
            }
        }


        bool ActionsceneProofComponent::doComponentScene(implements::IRadar* object) {
            // Execute the action of the selected scene object.
            if (!phase_->doAction(this)) {
                status_ = Evaluate::PROC_FAILED;
            }
            // When all scene objects have completed processing (null pointer state), transfer the control right to the next component.
            if (nullptr == phase_) {
                if (!object->changeComponents(nullptr)) {
                    status_ = Evaluate::PROC_FAILED;
                }
            }
            return true;
        }


        bool ActionsceneProofComponent::anomalyDetector(void) {
            if (Evaluate::PROC_FAILED == status_) {
                return true;
            }
            return false;
        }


        void ActionsceneProofComponent::setComponentState(implements::IComponentState* obj) {
            /*
             * NOTE :
             * As a system specification, the state object instance is not passed again from the null pointer state.
             * The act of setting an instance from the sky is done only in the constructor.
             * This is a IMPLEMENTATION CONSTRAINT.
             */
            if (nullptr != phase_) {
                delete phase_;
                phase_ = obj;
            }
        }

    }  // namespace C1_sample2

}  // namespace component