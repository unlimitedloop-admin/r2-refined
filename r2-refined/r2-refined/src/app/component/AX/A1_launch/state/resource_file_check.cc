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
 * This function checks whether resource data files can be used.
**/



/* INCLUDES */
// PRIMARY HEADER
#include "resource_file_check.h"
// PROJECT USING HEADER
#include "src/app/route/region/A1_launch_component.h"
#include "src/protocol/message_box.h"




/* SOURCES */
namespace component {

    namespace A1_launch {

        namespace state {

            bool ResourceFileCheckState::doAction(models::implements::IComponentStateContext* context) {
                // TODO : resource file checker.
                MSG_BOX(L"ResourceFileCheckState.doActionメソッドを実行しました。");
                context->setComponentState(route::region::A1LaunchComponent().getStates(this));
                return true;
            }

        }  // namespace state

    }  // namespace A1_launch

}  // namespace component