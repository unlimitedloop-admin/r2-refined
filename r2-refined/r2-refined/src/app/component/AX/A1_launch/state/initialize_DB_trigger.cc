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
//      File name       : resource_file_check.cc
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
 * Provides initialization processing for DB tables used in the main system.
**/



/* INCLUDES */
// PRIMARY HEADER
#include "initialize_DB_trigger.h"
// PROJECT USING HEADER
#include "src/app/route/region/A1_launch_component.h"
#include "src/protocol/message_box.h"




/* SOURCES */
namespace component {

    namespace A1_launch {

        namespace state {

            bool InitializeDBTriggerState::doAction(models::implements::IComponentStateContext* context) {
                // TODO : Call a initialize DB trigger.
                MSG_BOX(L"InitializeDBTriggerState.doActionメソッドを実行しました。");
                context->setComponentState(route::region::A1LaunchComponent().getStates(this));
                return true;
            }

        }  // namespace state

    }  // namespace A1_launch

}  // namespace component