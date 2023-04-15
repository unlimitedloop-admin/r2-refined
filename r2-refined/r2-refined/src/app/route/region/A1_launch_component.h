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
//      File name       : A1_launch_component.h
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
 * Set the state transition path of A1_launch.
**/



#ifndef _R2R_APP_ROUTE_REGION_A1_LAUNCH_COMPONENT_H_
#define _R2R_APP_ROUTE_REGION_A1_LAUNCH_COMPONENT_H_

/* INCLUDES */
// C++ SYSTEM HEADER
#include <typeinfo>
#include <string>
// PROJECT USING HEADER
#include "src/app/models/component_state.h"
#include "src/app/component/AX/A1_launch/launching_component.h"
#include "src/app/component/AX/A1_launch/state/resource_file_check.h"
#include "src/app/component/AX/A1_launch/state/initialize_DB_trigger.h"



/* SOURCES */
namespace route {

    namespace region {

        /* using namespace */
        using namespace models;
        using namespace component::A1_launch;



        class A1LaunchComponent final {

        public:
            A1LaunchComponent() {}
            A1LaunchComponent(const A1LaunchComponent&) = delete;
            ~A1LaunchComponent() {}

            /// <summary>
            /// Get the state instance of A1_launch.
            /// </summary>
            /// <param name=""></param>
            /// <returns></returns>
            implements::IComponentState* getStates(implements::IComponentState* instance) const;

        };


        inline implements::IComponentState* A1LaunchComponent::getStates(implements::IComponentState* instance) const {
            using namespace state;

            if (nullptr == instance) {
                return new ResourceFileCheckState();
            }
            else {
                const std::type_info& type = typeid(*instance);
                const std::wstring type_name = std::wstring(type.name(), type.name() + std::strlen(type.name()));
                const std::wstring namespace_tag = L"class component::A1_launch::state::";
                if (namespace_tag + L"ResourceFileCheckState" == type_name) {
                    return new InitializeDBTriggerState();
                }
                else {
                    return nullptr;
                }
            }
        }


        /*
         * Routes:
         * ResourceFileCheckState => InitializeDBTriggerState => @next component
         */


    }  // namespace region

}  // namespace route

#endif // !_R2R_APP_ROUTE_REGION_A1_LAUNCH_COMPONENT_H_