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
//      Last update     : 2023/04/29
//
//      File version    : 4
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
#include "src/app/models/component_state_context.h"
// PROJECT USING HEADER
#include "src/app/models/radar.h"
#include "src/app/models/component_state.h"
#include "src/protocol/evaluation.h"



/* SOURCES */
namespace component {

    namespace A1_launch {

        /* using namespace */
        using namespace protocol;
        using namespace models;



        /// <summary>
        /// Processing program launch class.
        /// </summary>
        class LaunchingComponent final : public implements::IComponents, public implements::IComponentStateContext {

        private:
            /// <summary>
            /// A phase state object.
            /// </summary>
            implements::IComponentState* phase_ = nullptr;

            /// <summary>
            /// A watch handler for the component. Set a dedicated value in case of error.
            /// </summary>
            Evaluate status_;

        public:
            LaunchingComponent();
            LaunchingComponent(const LaunchingComponent&) = delete;
            ~LaunchingComponent();

            /// <summary>
            /// Execute the contents of the component.
            /// </summary>
            /// <param name="object">Scene object</param>
            /// <returns>True or false, functions succeeded or failed</returns>
            bool doComponentScene(implements::IRadar* object) override;

            /// <summary>
            /// Check for any abnormalities.
            /// </summary>
            /// <param name="">Void</param>
            /// <returns>Returns true if there is an error</returns>
            bool anomalyDetector(void) override;

            /// <summary>
            /// Rewrite the value of the state member of the component.
            /// </summary>
            /// <param name="obj">State object (new instance)</param>
            void setComponentState(implements::IComponentState* obj) override;

        };

    }  // namespace A1_launch

}  // namespace component

#endif // !_R2R_APP_COMPONENT_AX_A1_LAUNCH_LAUNCHING_COMPONENT_H_