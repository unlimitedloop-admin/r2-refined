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
//      Last update     : 2023-03-05
//
//      File version    : 5
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
#include "src/app/component/sample_component.h"
#include "src/database/tables/MST_NES_PALETTE.h"



/* SOURCES */
namespace sequence {

    /* using namespace */
    using namespace DB;
    using namespace protocol;
    using namespace input;
    using namespace traceable;
    using namespace component;



    CursorPointer::CursorPointer() {
        (void)writeStatusLog("ゲームプログラムの運転を開始しました。");
        container_ = new SampleComponent1();
    }


    CursorPointer::~CursorPointer() {
        if (nullptr != container_) {
            delete container_;
            container_ = nullptr;
        }
        MST_NES_PALETTE::tr_0x0F();
    }


    Evaluate CursorPointer::Service(Evaluate evals) {
        // Update the gamepad key information.
        if (!GController()->updateJoyBtnStateKey()) {
            setStaticProcessCode(0x001EA1ULL, STATIC_ERR_DOMINATOR);
            return Evaluate::PROC_FAILED;
        }
        // ★ Please describe the sequencer controlling from here. >>>


        // ■ BEGIN TEST CODE >>>
        container_->doComponentScene(this);
        if (nullptr == container_) {
            return Evaluate::PROC_QUIT;
        }
        // ■ END TEST CODE.



        if (0 != DxLib::ScreenFlip()) { return Evaluate::PROC_FAILED; }
        return Evaluate::PROC_SUCCEED;
    }


    void CursorPointer::Exceptions(void) {
    }


    bool CursorPointer::changeComponents(implements::IComponents* object) {
        if (nullptr != container_) {
            delete container_;
            container_ = object;
        }
        return true;
    }

}  // namespace sequence