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
//      File name       : cursor_pointer.cc
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
 * It is the main core that controls the main program.
**/



/* INCLUDES */
// PRIMARY HEADER
#include "cursor_pointer.h"
// GENERAL USING HEADER
#include <DxLib.h>



/* SOURCES */
namespace sequence {

    CursorPointer::CursorPointer() {
        DxLib::SetBackgroundColor(255, 255, 255);   // ★ test code.
    }


    CursorPointer::~CursorPointer() {}


    protocol::Evaluate CursorPointer::Service(protocol::Evaluate evals) {
        return protocol::Evaluate::PROC_SUCCEED;
    }


    void CursorPointer::Exceptions(void) {
    }

}  // namespace sequence