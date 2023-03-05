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
//      File name       : radar.h
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
 * A behavioral interface that switches scenes for a component.
**/



#ifndef _R2R_APP_MODELS_RADAR_H_
#define _R2R_APP_MODELS_RADAR_H_

/* INCLUDES */
// PRIMARY HEADER
#include "components.h"



/* SOURCES */
namespace models {

    namespace implements {

        class IComponents;


        /// <summary>
        /// Scene changer interface.
        /// </summary>
        class IRadar {

        public:
            virtual ~IRadar() {}
            virtual bool changeComponents(IComponents* object) = 0;

        };

    }  // namespace implements

}  // namespace models

#endif // !_R2R_APP_MODELS_RADAR_H_