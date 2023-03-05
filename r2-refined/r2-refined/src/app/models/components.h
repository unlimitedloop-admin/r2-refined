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
//      File name       : components.h
//
//      Author          : u7
//
//      Last update     : 2023-03-05
//
//      File version    : 1
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * Component's interface as changes in every scene.
**/



#ifndef _R2R_APP_MODELS_COMPONENTS_H_
#define _R2R_APP_MODELS_COMPONENTS_H_

/* INCLUDES */
// PRIMARY HEADER
#include "radar.h"



/* SOURCES */
namespace models {

    namespace implements {

        class IRadar;


        /// <summary>
        /// Component interface.
        /// </summary>
        class IComponents {

        public:
            virtual ~IComponents() {}
            virtual bool doComponentScene(IRadar* object) = 0;

        };

    }  // namespace implements

}  // namespace models

#endif // !_R2R_APP_MODELS_COMPONENTS_H_