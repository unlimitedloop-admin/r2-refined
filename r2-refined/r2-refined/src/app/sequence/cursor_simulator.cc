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
//      Last update     : 2023-02-25
//
//      File version    : 3
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
#include "src/app/input/inputkey.h"
#include "src/traceable/output_logs.h"



/* SOURCES */
namespace sequence {

    /* using namespace */
    using namespace protocol;
    using namespace input;
    using namespace traceable;



    CursorSimulator::CursorSimulator() {
        (void)writeStatusLog("ゲームプログラムの運転を開始しました。[DEVELOPMENT MODE IS ENABLED]");
    }


    CursorSimulator::~CursorSimulator() {}


    Evaluate CursorSimulator::Service(Evaluate evals) {
        // Update the gamepad key information.
        if (!GController()->updateJoyBtnStateKey()) {
            setStaticProcessCode(0x001EA1ULL, STATIC_ERR_DOMINATOR);
            return Evaluate::PROC_FAILED;
        }
        // TODO : Please describe the sequencer controlling from here. >>>






        if (0 != DxLib::ScreenFlip()) { return Evaluate::PROC_FAILED; }
        return Evaluate::PROC_SUCCEED;
    }


    void CursorSimulator::Exceptions(void) {
    }

}  // namespace sequence