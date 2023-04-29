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
//      File name       : setup_instance.cc
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
 * Implement a proof-of-concept instance read for an action scene program.
**/



/* INCLUDES */
// PRIMARY HEADER
#include "setup_instance.h"
// PROJECT USING HEADER
#include "src/app/models/component_state_context.h"




/* SOURCES */
namespace component {
    
    namespace C1_sample2 {

        namespace state {

            bool SetupInstanceState::doAction(implements::IComponentStateContext* context) {

                return false;
            }

        }  // namespace state

    }  // namespace C1_sample2

}  // namespace component