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
//      File name       : initialize_run_DB_trigger.h
//
//      Author          : u7
//
//      Last update     : 2023/04/15
//
//      File version    : 1
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * initialize run DB trigger.header
**/



#ifndef _R2R_APP_COMPONENT_AX_A1_LAUNCH_STATE_INITIALIZE_DB_TRIGGER_H_
#define _R2R_APP_COMPONENT_AX_A1_LAUNCH_STATE_INITIALIZE_DB_TRIGGER_H_

/* INCLUDES */
// PRIMARY HEADER
#include "src/app/models/component_state.h"
// PROJECT USING HEADER
#include "src/app/models/component_state_context.h"




/* SOURCES */
namespace component {

    namespace A1_launch {

        namespace state {

            class InitializeDBTriggerState final : public models::implements::IComponentState {

            public:
                InitializeDBTriggerState() {}
                InitializeDBTriggerState(const InitializeDBTriggerState&) = delete;
                ~InitializeDBTriggerState() {}

                /// <summary>
                /// Do action of state.
                /// </summary>
                /// <param name="context">A context object that controls state</param>
                /// <returns>Returns true if successful</returns>
                bool doAction(models::implements::IComponentStateContext* context) override;

            };

        }  // namespace state

    }  // namespace A1_launch

}  // namespace component

#endif // !_R2R_APP_COMPONENT_AX_A1_LAUNCH_STATE_INITIALIZE_DB_TRIGGER_H_