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
//      Last update     : 2023/03/01
//
//      File version    : 4
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
// PROJECT USING HEADER
#include "src/protocol/evaluation.h"
#include "src/protocol/process_code_hard.h"
#include "src/protocol/message_box.h"
#include "src/app/input/inputkey.h"
#include "src/traceable/output_logs.h"



/* SOURCES */
namespace sequence {

    /* using namespace */
    using namespace protocol;
    using namespace input;
    using namespace traceable;




    CursorPointer::CursorPointer() {
        (void)writeStatusLog("ゲームプログラムの運転を開始しました。");
    }


    CursorPointer::~CursorPointer() {}


    Evaluate CursorPointer::Service(Evaluate evals) {
        // Update the gamepad key information.
        if (!GController()->updateJoyBtnStateKey()) {
            setStaticProcessCode(0x001EA1ULL, STATIC_ERR_DOMINATOR);
            return Evaluate::PROC_FAILED;
        }
        // ★ Please describe the sequencer controlling from here. >>>






        if (0 != DxLib::ScreenFlip()) { return Evaluate::PROC_FAILED; }
        return Evaluate::PROC_SUCCEED;
    }


    void CursorPointer::Exceptions(void) {
    }

}  // namespace sequence