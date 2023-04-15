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
//      File name       : component_state.h
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
 * A state interface that represents the state inside a component.
**/



#ifndef _R2R_APP_MODELS_COMPONENT_STATE_H_
#define _R2R_APP_MODELS_COMPONENT_STATE_H_

/* INCLUDES */
// PRIMARY HEADER
#include "component_state_context.h"



/* SOURCES */
namespace models {

    namespace implements {

        /// <summary>
        /// State context interface for mutating state.
        /// </summary>
        class IComponentStateContext;


        /// <summary>
        /// An interface that holds the state of a component.
        /// </summary>
        class IComponentState {

        public:
            virtual ~IComponentState() {}
            virtual bool doAction(IComponentStateContext* context) = 0;

        };

    }  // namespace implements

}  // namespace models

#endif // !_R2R_APP_MODELS_COMPONENT_STATE_H_