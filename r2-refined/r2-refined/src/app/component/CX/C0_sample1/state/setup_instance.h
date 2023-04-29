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
//      File name       : setup_instance.h
//
//      Author          : u7
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * setup instance.header
**/



#ifndef _R2R_APP_COMPONENT_CX_C0_SAMPLE1_STATE_SETUP_INSTANCE_H_
#define _R2R_APP_COMPONENT_CX_C0_SAMPLE1_STATE_SETUP_INSTANCE_H_

/* INCLUDES */
// PRIMARY HEADER
#include "src/app/models/component_state.h"
// PROJECT USING HEADER
#include "src/app/models/component_state_context.h"
#include "src/protocol/message_box.h"



/* SOURCES */
namespace component {

    namespace C0_sample1 {

        namespace state {

            /* using namespace */
            using namespace models;



            class SetupInstanceState final : public implements::IComponentState {

            public:
                SetupInstanceState() {}
                ~SetupInstanceState() {}

                bool doAction(implements::IComponentStateContext* context) override;

            };


            inline bool SetupInstanceState::doAction(implements::IComponentStateContext* context) {
                MSG_BOX(L"This is \"C0_sample1\".");
                return false;
            }

        }  // namespace state

    }  // namespace C0_sample1

}  // namespace component

#endif // !_R2R_APP_COMPONENT_CX_C0_SAMPLE1_STATE_SETUP_INSTANCE_H_