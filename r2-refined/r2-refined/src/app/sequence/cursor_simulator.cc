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
//      File name       : cursor_simulator.cc
//
//      Author          : u7
//
//      Last update     : 2023/02/25
//
//      File version    : 2
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * You can use this cursor pointer to validate the module classes used by the application.
**/



/* INCLUDES */
// PRIMARY HEADER
#include "cursor_simulator.h"
// GENERAL USING HEADER
#include <DxLib.h>
// PROJECT USING HEADER
#include "src/protocol/evaluation.h"



/* SOURCES */
namespace sequence {

    /* using namespace */
    using namespace protocol;




    CursorSimulator::CursorSimulator() {
        DxLib::SetBackgroundColor(128, 255, 128);   // ★ test code.
    }


    CursorSimulator::~CursorSimulator() {}


    Evaluate CursorSimulator::Service(Evaluate evals) {
        return Evaluate::PROC_SUCCEED;
    } 


    void CursorSimulator::Exceptions(void) {
    }

}  // namespace sequence