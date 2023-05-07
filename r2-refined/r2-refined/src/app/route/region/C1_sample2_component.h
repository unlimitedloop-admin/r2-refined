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
//      Last update     : 2023/05/07
//
//      File version    : 2
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
#include "src/app/component/CX/C1_sample2/state/proof_stage_main.h"
#include "src/app/matter/blending/dealer.h"



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
            /// Get the state instance of C1_sample2.
            /// </summary>
            /// <param name="instance">Latest state instance</param>
            /// <param name="mat_impl">Material management object pointer</param>
            /// <returns>Next placeholder instance</returns>
            implements::IComponentState* getStates(implements::IComponentState* instance, matter::blending::Dealer* mat_impl);

        };


        inline implements::IComponentState* C1Sample2Component::getStates(implements::IComponentState* instance, matter::blending::Dealer* mat_impl) {
            using namespace state;

            if (nullptr == instance) {
                return new SetupInstanceState(mat_impl);
            }
            else {
                const std::type_info& type = typeid(*instance);
                const std::wstring type_name = std::wstring(type.name(), type.name() + std::strlen(type.name()));
                const std::wstring namespace_tag = L"class component::C1_sample2::state::";
                if (namespace_tag + L"SetupInstanceState" == type_name) {
                    return new ProofStageMainState(mat_impl);
                }
                //else if (namespace_tag + L"ProofStageMainState" == type_name) {
                //    return new ReleaseAllAllocState();
                //}
                else {
                    return nullptr;
                }
            }
            return nullptr;
        }


        /*
         * Routes:
         * SetupInstanceState => ProofStageMainState => ReleaseAllAllocState => @next component
         */


    }  // namespace region

}  // namespace route

#endif // !_R2R_APP_ROUTE_REGION_C1_SAMPLE2_COMPONENT_H_