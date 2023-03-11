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
//      File name       : launching_component.h
//
//      Author          : u7
//
//      Last update     : 2023/03/11
//
//      File version    : 1
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * launching component.header 
**/



#ifndef _R2R_APP_COMPONENT_AX_A1_LAUNCH_LAUNCHING_COMPONENT_H_
#define _R2R_APP_COMPONENT_AX_A1_LAUNCH_LAUNCHING_COMPONENT_H_

/* INCLUDES */
// PRIMARY HEADER
#include "src/app/models/components.h"
// PROJECT USING HEADER
#include "src/app/models/radar.h"



/* SOURCES */
namespace component {

    namespace A1_launch {

        /* using namespace */ 
        using namespace models;



        /// <summary>
        /// Processing program launch class.
        /// </summary>
        class LaunchingComponent final : public implements::IComponents {

        public:
            LaunchingComponent();
            LaunchingComponent(const LaunchingComponent&) = delete;
            ~LaunchingComponent() {}

            /// <summary>
            /// Execute the contents of the component.
            /// </summary>
            /// <param name="object">Scene object</param>
            /// <returns>True or false, functions succeeded or failed</returns>
            bool doComponentScene(implements::IRadar* object) override;

        };

    }  // namespace A1_launch

}  // namespace component

#endif // !_R2R_APP_COMPONENT_AX_A1_LAUNCH_LAUNCHING_COMPONENT_H_