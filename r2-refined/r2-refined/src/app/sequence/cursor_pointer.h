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
//      Last update     : 2023/03/07
//
//      File version    : 5
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
#include "src/app/models/radar.h"
// PROJECT USING HEADER
#include "src/protocol/evaluation.h"
#include "src/app/models/components.h"



/* SOURCES */
namespace sequence {

    /* using namespace */
    using namespace models;
    using namespace protocol;



    /// <summary>
    /// A behavior cursor that controls the phases of the main program.
    /// </summary>
    class CursorPointer final : public implements::ICursor, public implements::IRadar {
    private:
        /// <summary>
        /// Component container.
        /// </summary>
        implements::IComponents* container_;
    
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

        /// <summary>
        /// Change the component.
        /// </summary>
        /// <param name="object">Component object</param>
        /// <returns>True or false, functions succeeded or failed</returns>
        bool changeComponents(implements::IComponents* object) override;
    };

}  // namespace sequence

#endif // !_R2R_APP_SEQUENCE_CURSOR_POINTER_H_