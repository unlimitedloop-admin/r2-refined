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
//      File name       : cursor_simulator.h
//
//      Author          : u7
//
//      Last update     : 2023/03/11
//
//      File version    : 4
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * cursor simulator.header
**/



#ifndef _R2R_APP_SEQUENCE_CURSOR_SIMULATOR_H_
#define _R2R_APP_SEQUENCE_CURSOR_SIMULATOR_H_

/* INCLUDES */
// PRIMARY HEADER
#include "src/app/models/cursor.h"
// PROJECT USING HEADER
#include "src/app/models/components.h"
#include "src/protocol/evaluation.h"



/* SOURCES */
namespace sequence {

    /* using namespace */
    using namespace protocol;
    using namespace models;



    /// <summary>
    /// A behavior cursor that controls the main program for development.
    /// </summary>
    class CursorSimulator final : public implements::ICursor {
    
    private:
        /// <summary>
        /// Component container.
        /// </summary>
        implements::IComponents* container_;


    public:
        CursorSimulator();
        CursorSimulator(const CursorSimulator&) = delete;
        ~CursorSimulator();

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

#endif // !_R2R_APP_SEQUENCE_CURSOR_SIMULATOR_H_