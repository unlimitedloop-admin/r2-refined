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
//      File name       : cursor.h
//
//      Author          : u7
//
//      Last update     : 2023/03/01
//
//      File version    : 2
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * cursor.header
**/



#ifndef _R2R_APP_MODELS_CURSOR_H_
#define _R2R_APP_MODELS_CURSOR_H_

/* INCLUDES */
// PROJECT USING HEADER
#include "src/protocol/evaluation.h"



/* SOURCES */
namespace models {

    /* using namespace */
    using namespace protocol;



    namespace implements {

        /// <summary>
        /// Interface for cursor classes.
        /// </summary>
        class ICursor {
        public:
            virtual ~ICursor() {}
            virtual Evaluate Service(Evaluate evals) = 0;
            virtual void Exceptions(void) = 0;
        };

    }  // namespace implements

}  // namespace models

#endif // !_R2R_APP_MODELS_CURSOR_H_