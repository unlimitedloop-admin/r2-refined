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
//      File name       : launching_component.cc
//
//      Author          : u7
//
//      Last update     : 2023/04/15
//
//      File version    : 3
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * A set of actions to be executed at the beginning of the main.
**/



/* INCLUDES */
// PRIMARY HEADER
#include "launching_component.h"
// PROJECT USING HEADER
#include "src/app/models/radar.h"
#include "src/protocol/evaluation.h"
#include "src/traceable/output_logs.h"
#include "src/app/route/region/A1_launch_component.h"



/* SOURCES */
namespace component {

    namespace A1_launch {

        /* using namespace */
        using namespace protocol;
        using namespace models;
        using namespace traceable;




        LaunchingComponent::LaunchingComponent() : status_(Evaluate::PROC_SUCCEED) {
            phase_ = route::region::A1LaunchComponent().getStates(phase_);
            (void)writeStatusLog(L"LaunchingComponentクラスの実行を開始しました。");
        }


        bool LaunchingComponent::doComponentScene(implements::IRadar* object) {
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


        bool LaunchingComponent::anomalyDetector(void) {
            if (Evaluate::PROC_FAILED == status_) {
                return true;
            }
            return false;
        }


        void LaunchingComponent::setComponentState(implements::IComponentState* obj) {
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

    }  // namespace A1_launch

}  // namespace component