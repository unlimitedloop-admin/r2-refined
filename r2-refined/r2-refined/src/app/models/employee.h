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
//      File name       : employee.h
//
//      Author          : u7
//
//      Last update     : 2023/05/07
//
//      File version    : 1
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * employee interface (abstract class).
**/



#ifndef _R2R_APP_MODELS_EMPLOYEE_H_
#define _R2R_APP_MODELS_EMPLOYEE_H_

/* INCLUDES */
// PROJECT USING HEADER
#include "src/app/matter/blending/dealer.h"



/* SOURCES */
namespace models {

    namespace implements {

        /// <summary>
        /// The interface of the "action system".
        /// </summary>
        class IEmployee {

        public:
            virtual ~IEmployee() {}
            virtual bool Work(matter::blending::Dealer* impl) = 0;

        };

    }  // namespace implements

}  // namespace models

#endif // !_R2R_APP_MODELS_EMPLOYEE_H_