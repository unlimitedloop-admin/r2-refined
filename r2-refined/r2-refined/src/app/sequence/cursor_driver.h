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
//      File name       : cursor_driver.h
//
//      Author          : u7
//
//
//
//
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * cursor driver.header
**/



#ifndef _R2R_APP_SEQUENCE_CURSOR_DRIVER_H_
#define _R2R_APP_SEQUENCE_CURSOR_DRIVER_H_

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
    using namespace protocol;
    using namespace models;




    class CursorDriver : public implements::ICursor, public implements::IRadar {
    private:
        implements::IComponents* container_;

    public:
        CursorDriver();
        CursorDriver(const CursorDriver&) = delete;
        ~CursorDriver();

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


        bool changeComponents(implements::IComponents* object) override;
    };

}  // namespace sequence

#endif // !_R2R_APP_SEQUENCE_CURSOR_DRIVER_H_