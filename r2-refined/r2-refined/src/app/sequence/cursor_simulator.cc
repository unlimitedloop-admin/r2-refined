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
//      Last update     : 2023/03/05
//
//      File version    : 5
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
#include "src/database/tables/MST_NES_PALETTE.h"



/* SOURCES */
namespace sequence {

    /* using namespace */
    using namespace DB;
    using namespace protocol;
    using namespace input;
    using namespace traceable;



    CursorSimulator::CursorSimulator() {
        (void)writeStatusLog("ゲームプログラムの運転を開始しました。[DEVELOPMENT MODE IS ENABLED]");
    }


    CursorSimulator::~CursorSimulator() {
        MST_NES_PALETTE::tr_0x0F();
    }


    Evaluate CursorSimulator::Service(Evaluate evals) {
        // Update the gamepad key information.
        if (!GController()->updateJoyBtnStateKey()) {
            setStaticProcessCode(0x001EA1ULL, STATIC_ERR_DOMINATOR);
            return Evaluate::PROC_FAILED;
        }
        // ★ Please describe the sequencer controlling from here. >>>






        if (0 != DxLib::ScreenFlip()) { return Evaluate::PROC_FAILED; }
        return Evaluate::PROC_SUCCEED;
    }


    void CursorSimulator::Exceptions(void) {
    }

}  // namespace sequence