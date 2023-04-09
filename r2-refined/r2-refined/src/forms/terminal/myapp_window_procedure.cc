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
//      File name       : myapp_window_procedure.cc
//
//      Author          : u7
//
//      Last update     : 2023/04/09
//
//      File version    : 2
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * Implements a user specified window procedure.
**/



/* INCLUDES */
// PRIMARY HEADER
#include "app_engine.h"
// C++ SYSTEM HEADER
#include <functional>
// GENERAL USING HEADER
#include <Windows.h>
#include <DxLib.h>
// PROJECT USING HEADER
#include "resource.h"
#include "src/protocol/process_code_hard.h"
#include "src/protocol/xglobals.h"
#include "src/exceptions/exception_handler.h"



/* SOURCES */
namespace terminal {

    /* using namespace */
    using namespace protocol;



    /// <summary>
    /// User-specified window procedure.
    /// </summary>
    LRESULT CALLBACK DefinitiveProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        switch (msg) {
        case WM_COMMAND:
            switch (LOWORD(wParam)) {
            case ID_40001:  // ゲーム開始^   F1
                setAppsActiveFlag(true);
                break;
            case ID_40005:  // 停止
                setAppsActiveFlag(false);
                break;
            case ID_40008:  // 終了^  Alt+F4
                SendMessage(xg_hWnd, WM_CLOSE, NULL, NULL);
                break;
            }
            break;
        }
        return CallWindowProc(xg_DxLibWnd, hWnd, msg, wParam, lParam);
    }


    bool AppEngine::setAccelaratorCommand(void) const {
        if (0 != DxLib::SetUseKeyAccelFlag(TRUE)) {
            setStaticProcessCode(0x0018B0ULL, STATIC_ERR_DOMINATOR);
            return false;
        }
        if (0 != DxLib::AddKeyAccel_ID(ID_40001, KEY_INPUT_F1, FALSE, FALSE, FALSE)) {
            setStaticProcessCode(0x0019B0ULL, STATIC_ERR_DOMINATOR);
            return false;
        }
        return true;
    }


    bool AppEngine::registeredClientSystem(std::function<bool(uint64_t)> func) {
        // NOTE : The fact that GetUseMenuFlag is true is proof that the window process is scanning in this run. Therefore, register the window handle.
        if (DxLib::GetUseMenuFlag()) {
            xg_hWnd = DxLib::GetMainWindowHandle();
            xg_DxLibWnd = (WNDPROC)GetWindowLongPtr(xg_hWnd, GWLP_WNDPROC);
            xg_hInstance = DxLib::GetTaskInstance();
            if (!this->setAccelaratorCommand()) { return false; }
            if (!SetWindowLongPtr(xg_hWnd, GWLP_WNDPROC, (LONG_PTR)DefinitiveProc)) { return func(0x001CD0ULL); }
        }
        else {
            // NOTE : Automatically run the game program when in full screen mode. (because there is no menu bar)
            setAppsActiveFlag(true);
            NATIVE_MSG(L"全画面モードでゲームを開始できませんでした。");
            if (getStaticBindingFailureFlag()) { return false; }
        }
        return true;
    }

}  // namespace terminal