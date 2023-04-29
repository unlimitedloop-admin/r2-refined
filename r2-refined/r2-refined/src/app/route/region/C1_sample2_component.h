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
//      File name       : C1_sample2_component.h
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
 * Set the state transition path of C1_sample2.
**/



#ifndef _R2R_APP_ROUTE_REGION_C1_SAMPLE2_COMPONENT_H_
#define _R2R_APP_ROUTE_REGION_C1_SAMPLE2_COMPONENT_H_

/* INCLUDES */
// C++ SYSTEM HEADER
#include <typeinfo>
#include <string>
// PROJECT USING HEADER
#include "src/app/models/component_state.h"
#include "src/app/component/CX/C1_sample2/actionscene_proof_component.h"
#include "src/app/component/CX/C1_sample2/state/setup_instance.h"



/* SOURCES */
namespace route {

    namespace region {

        /* using namespace */
        using namespace models;
        using namespace component::C1_sample2;



        class C1Sample2Component final {

        public:
            C1Sample2Component() {}
            C1Sample2Component(const C1Sample2Component&) = delete;
            ~C1Sample2Component() {}

            /// <summary>
            /// Get the state instance of A1_launch.
            /// </summary>
            /// <param name="">Void</param>
            /// <returns>Next placeholder instance</returns>
            implements::IComponentState* getStates(implements::IComponentState* instance) const;

        };


        inline implements::IComponentState* C1Sample2Component::getStates(implements::IComponentState* instance) const {
            using namespace state;

            if (nullptr == instance) {
                return new SetupInstanceState();
            }
            else {
                //const std::type_info& type = typeid(*instance);
                //const std::wstring type_name = std::wstring(type.name(), type.name() + std::strlen(type.name()));
                //const std::wstring namespace_tag = L"class component::A1_launch::state::";
                //if (namespace_tag + L"ResourceFileCheckState" == type_name) {
                //    return new InitializeDBTriggerState();
                //}
                //else {
                //    return nullptr;
                //}
            }
            return nullptr;
        }


        /*
         * Routes:
         * SetupInstanceState => ???? => ???? => @next component
         */


    }  // namespace region

}  // namespace route

#endif // !_R2R_APP_ROUTE_REGION_C1_SAMPLE2_COMPONENT_H_