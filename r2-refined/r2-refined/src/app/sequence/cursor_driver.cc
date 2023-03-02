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
//      File name       : cursor_driver.cc
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
 * It's for verification.
**/



/* INCLUDES */
// PRIMARY HEADER
#include "cursor_driver.h"
// GENERAL USING HEADER
#include <DxLib.h>
// PROJECT USING HEADER
#include "src/protocol/evaluation.h"
#include "src/protocol/process_code_hard.h"
#include "src/protocol/message_box.h"
#include "src/app/input/inputkey.h"

#include "src/app/input/key_binding.h"



/* SOURCES */
namespace sequence {

    /* using namespace */
    using namespace protocol;
    using namespace input;




    CursorDriver::CursorDriver() {
        DxLib::SetBackgroundColor(255, 255, 255);
    }


    CursorDriver::~CursorDriver() {}


    Evaluate CursorDriver::Service(Evaluate evals) {
        // Update the gamepad key information.
        if (!GController()->updateJoyBtnStateKey()) {
            setStaticProcessCode(0x001EA1ULL, STATIC_ERR_DOMINATOR);
            return Evaluate::PROC_FAILED;
        }

        // Added proof code at the 2023-02-25. >>>
        /* Specify GetKey (JPBTN enumeration identifier) to get the value of the gamepad or keyboard. */
        if (GetKey(JPBTN::START)) {
            MSG_BOX("ゲームプログラムを終了するビヘイビアーサンプルです。");
            return Evaluate::PROC_QUIT;
        }
        DxLib::DrawFormatString(2, 2, DxLib::GetColor(0, 0, 0), "Aボタンの現在値：%d", GetKey(JPBTN::A));
        DxLib::DrawFormatString(2, 26, DxLib::GetColor(0, 0, 0), "Bボタンの現在値：%d", GetKey(JPBTN::B));
        DxLib::DrawFormatString(2, 50, DxLib::GetColor(0, 0, 0), "Xボタンの現在値：%d", GetKey(JPBTN::X));
        DxLib::DrawFormatString(2, 74, DxLib::GetColor(0, 0, 0), "Yボタンの現在値：%d", GetKey(JPBTN::Y));


        if (0 != DxLib::ScreenFlip()) { return Evaluate::PROC_FAILED; }
        return Evaluate::PROC_SUCCEED;
    }


    void CursorDriver::Exceptions(void) {
    }

}  // namespace sequence