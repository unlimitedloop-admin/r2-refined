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
//      Last update     : 2023/02/22
//
//      File version    : 1
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

    CursorSimulator::CursorSimulator() {
        DxLib::SetBackgroundColor(128, 255, 128);   // ★ test code.
    }


    CursorSimulator::~CursorSimulator() {}


    protocol::Evaluate CursorSimulator::Service(protocol::Evaluate evals) {
        return protocol::Evaluate::PROC_SUCCEED;
    } 


    void CursorSimulator::Exceptions(void) {
    }

}  // namespace sequence