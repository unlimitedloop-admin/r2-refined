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
//      File name       : component_state_context.h
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
 * Provides an interface to control the behavior of state classes contained in components.
**/



#ifndef _R2R_APP_MODELS_COMPONENT_STATE_CONTEXT_H_
#define _R2R_APP_MODELS_COMPONENT_STATE_CONTEXT_H_

/* INCLUDES */
// PRIMARY HEADER
#include "component_state.h"



/* SOURCES */
namespace models {

    namespace implements {

        /// <summary>
        /// An interface that holds the state of a component.
        /// </summary>
        class IComponentState;


        /// <summary>
        /// State context interface for mutating state.
        /// </summary>
        class IComponentStateContext {

        public:
            virtual ~IComponentStateContext() {}
            virtual void setComponentState(IComponentState* obj) = 0;

        };

    }  // namespace implements

}  // namespace models

#endif // !_R2R_APP_MODELS_COMPONENT_STATE_CONTEXT_H_