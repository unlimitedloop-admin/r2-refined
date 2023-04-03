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
//      Last update     : 2023/04/03
//
//      File version    : 2
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
#include "src/traceable/output_logs.h"



/* SOURCES */
namespace component {

    namespace A1_launch {

        /* using namespace */
        using namespace models;
        using namespace traceable;




        LaunchingComponent::LaunchingComponent() {
            (void)writeStatusLog(L"LaunchingComponentクラスの実行を開始しました。");
        }


        bool LaunchingComponent::doComponentScene(implements::IRadar* object) {
            return true;
        }

    }  // namespace A1_launch

}  // namespace component