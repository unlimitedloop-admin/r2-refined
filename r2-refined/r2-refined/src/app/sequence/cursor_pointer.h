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
//      File name       : cursor_pointer.h
//
//      Author          : u7
//
//      Last update     : 2023/03/01
//
//      File version    : 3
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * cursor pointer.header
**/



#ifndef _R2R_APP_SEQUENCE_CURSOR_POINTER_H_
#define _R2R_APP_SEQUENCE_CURSOR_POINTER_H_

/* INCLUDES */
// PRIMARY HEADER
#include "src/app/models/cursor.h"
// PROJECT USING HEADER
#include "src/protocol/evaluation.h"



/* SOURCES */
namespace sequence {

    /* using namespace */
    using namespace models;
    using namespace protocol;



    /// <summary>
    /// A behavior cursor that controls the phases of the main program.
    /// </summary>
    class CursorPointer final : public implements::ICursor {
    public:
        CursorPointer();
        CursorPointer(const CursorPointer&) = delete;
        ~CursorPointer();

        /// <summary>
        /// Do trying for process of simulator.
        /// </summary>
        /// <param name="evals">Enumeration representing the execution result</param>
        /// <returns>Processing report enum</returns>
        Evaluate Service(Evaluate evals) override;

        /// <summary>
        /// Exception handling.
        /// </summary>
        /// <param name="">Void</param>
        void Exceptions(void) override;
    };

}  // namespace sequence

#endif // !_R2R_APP_SEQUENCE_CURSOR_POINTER_H_