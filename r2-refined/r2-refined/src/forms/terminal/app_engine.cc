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
//      File name       : app_engine.cc
//
//      Author          : u7
//
//      Last update     : 2023/03/05
//
//      File version    : 8
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * The main game engine at the core of this application.
**/



/* INCLUDES */
// PRIMARY HEADER
#include "app_engine.h"
// C++ SYSTEM HEADER
#include <string>
// GENERAL USING HEADER
#include <Windows.h>
#include <DxLib.h>
#include <stdlib.h>
// PROJECT USING HEADER
#include "src/forms/device/keyboards_in.h"
#include "src/exceptions/exception_handler.h"
#include "src/protocol/evaluation.h"
#include "src/protocol/env_params.h"
#include "src/protocol/process_code_hard.h"
#include "src/protocol/xglobals.h"
#include "src/traceable/output_logs.h"
#include "src/util/conv/converting.h"               /* UTILITY MODULES */
#include "resource.h"
#include "src/app/input/key_binding.h"
#include "src/app/sequence/cursor_pointer.h"
#include "src/app/sequence/cursor_simulator.h"
#include "src/app/sequence/cursor_driver.h"



/* SOURCES */
namespace {

    /* using namespace */
    using namespace protocol;
    using namespace traceable;


    /* using alias */
    using GAMEPROC = bool;


    /* local scopes */
    ResultSet   dev_mode = ResultSet::DISABLED;     // Development running mode of applications
    ResultSet   test_driver = ResultSet::DISABLED;  // Test driver running flag
    GAMEPROC    apps_active;                        // Activation supervisor
    Activator   activator;                          // Main program activator key




    void setAppsActiveFlag(bool flag) {
        if (flag != apps_active) {
            apps_active = flag;
            if (apps_active) {
                if (ResultSet::ENABLED == test_driver) { activator = Activator::CHANGE_DRIVER; }
                else if (ResultSet::ENABLED == dev_mode) { activator = Activator::CHANGE_DEVELOPPROC; }
                else { activator = Activator::CHANGE_MAINPROC; }

                if (0 != SetDrawScreen(DX_SCREEN_BACK)) {
                    setStaticProcessCode(0x0005B0LL, STATIC_ERR_DOMINATOR);
                    setStaticBindingFailureFlag(true);
                }
            }
            else {
                activator = Activator::NOT_ACTIVATION;
                if (0 != SetDrawScreen(DX_SCREEN_FRONT)) {
                    setStaticProcessCode(0x0006B0LL, STATIC_ERR_DOMINATOR);
                    setStaticBindingFailureFlag(true);
                }
            }
        }
    }


    bool setAccelaratorCommand(void) {
        if (0 != SetUseKeyAccelFlag(TRUE)) {
            setStaticProcessCode(0x0018B0ULL, STATIC_ERR_DOMINATOR);
            return false;
        }
        if (0 != AddKeyAccel_ID(ID_40001, KEY_INPUT_F1, FALSE, FALSE, FALSE)) {
            setStaticProcessCode(0x0019B0ULL, STATIC_ERR_DOMINATOR);
            return false;
        }
        return true;
    }

}  // plain namespace



namespace terminal {

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


    AppEngine::~AppEngine() {
        if (nullptr != sequence_) {
            delete sequence_;
            sequence_ = nullptr;
        }
    }


    bool AppEngine::Receptions(RunMode ticket) {
        switch (activator) {
        case Activator::NOT_ACTIVATION:
            if (nullptr != sequence_) {
                delete sequence_;
                sequence_ = nullptr;
                (void)writeStatusLog("ゲームプログラムの運転を停止しました。");
            }
            break;
        case Activator::CHANGE_MAINPROC:
            if (nullptr == sequence_) {
                sequence_ = new sequence::CursorPointer();
            }
            break;
        case Activator::CHANGE_DEVELOPPROC:
            if (nullptr == sequence_) {
                sequence_ = new sequence::CursorSimulator();
            }
            break;
        case Activator::CHANGE_DRIVER:
            if (nullptr == sequence_) {
                sequence_ = new sequence::CursorDriver();
            }
            break;
        case Activator::DISABLED:
            break;
        default:
            setStaticProcessCode(0x0011B1ULL, STATIC_ERR_DOMINATOR);
            NATIVE_MSG("#Activator: %d", static_cast<int>(activator));
            return false;
        }
        activator = Activator::DISABLED;
        return true;
    }


    bool AppEngine::Initialize(RunMode indicator) const {
        std::string str;
        auto exceptions = [](unsigned __int64 code) { setStaticProcessCode(code, STATIC_ERR_DOMINATOR); return false; };

        /* ******* Pick up an environment variable and set up its value in this system. ******* */
        str.clear();
        if (getParameter("$HIDDEN_DRIVER", &str)) {
            if ("1" == str) {
                test_driver = ResultSet::ENABLED;
                (void)writeStatusLog("テストモジュールを起動します。", LogClass::LOG_LEVEL_OFF);
            }
        }
        // Check for development mode flag. (For development, normally 0)
        else if (getParameter("$DEV_MODE", &str)) {
            if ("1" == str) {
                dev_mode = ResultSet::ENABLED;
                (void)writeStatusLog("システムはデヴェロップメントモードで開始されます。", LogClass::LOG_LEVEL_OFF);
            }
        }
        // Output DxLib log. Specify the output destination of the DxLib exclusive log before calling the DxLib function. 
        if (RunMode::GENERAL_MODE == indicator) {
            if (0 != SetOutApplicationLogValidFlag(FALSE)) { exceptions(0x000771ULL); }
        }
        else {
            if (getParameter("$DXLIB_OUTPUT_LOG_PATH", &str)) {
                if (0 != SetApplicationLogSaveDirectory(str.c_str())) { exceptions(0x000871ULL); }
            }
            else {
                if (0 != SetOutApplicationLogValidFlag(FALSE)) { exceptions(0x000771ULL); }
            }
        }
        // Active (or inactive) window always running application.
        str.clear();
        if (getParameter("$WINDOW_ALWAYS_RUN_ENABLED", &str)) {
            if ("1" == str) {
                if (0 != SetAlwaysRunFlag(TRUE)) { exceptions(0x000951ULL); }
            }
            else {
                if (0 != SetAlwaysRunFlag(FALSE)) { exceptions(0x000A51ULL); }
            }
        }
        // Screen setup.
        str.clear();
        (void)getParameter("$WINDOW_MODE_ENABLED", &str);
        if ("0" == str) {
            if (DX_CHANGESCREEN_OK != ChangeWindowMode(FALSE)) { exceptions(0x000BF1ULL); }
            if (0 != SetUseMenuFlag(FALSE)) { exceptions(0x000C91ULL); }
        }
        else {
            // Default route.
            if (DX_CHANGESCREEN_OK != ChangeWindowMode(TRUE)) { exceptions(0x000DF1ULL); }
            if (0 != SetWindowPosition(10, 10)) { exceptions(0x000E71ULL); }
            str.clear();
            if (getParameter("$WINDOW_EXTEND_RATE", &str)) {
                double rate;
                if (!str.empty() && util_conv::tryParseStrToDouble(&rate, str)) {
                    if (0 != SetWindowSizeExtendRate(rate)) { exceptions(0x000F70ULL); }
                }
            }
            auto size = 0, winsizex = 0, winsizey = 0, colorbit = 0;
            str.clear();
            (void)getParameter("$WINDOW_HORIZONAL_SIZE", &str);
            if (!str.empty() && util_conv::tryParseStrToInt(&size, str)) winsizex = size;
            str.clear();
            (void)getParameter("$WINDOW_VERTICAL_SIZE", &str);
            if (!str.empty() && util_conv::tryParseStrToInt(&size, str)) winsizey = size;
            str.clear();
            (void)getParameter("$WINDOW_COLOR_BITS", &str);
            if (!str.empty() && util_conv::tryParseStrToInt(&size, str)) colorbit = size;
            if (winsizex && winsizey && colorbit) {
                if (DX_CHANGESCREEN_OK != SetGraphMode(winsizex, winsizey, colorbit)) {
                    if (DX_CHANGESCREEN_OK != SetGraphMode(256, 240, 16)) { exceptions(0x0012F1ULL); }
                }
            }
            else {
                if (DX_CHANGESCREEN_OK != SetGraphMode(256, 240, 16)) { exceptions(0x0012F1ULL); }
                if (0 != SetWindowSizeExtendRate(1.0)) { exceptions(0x000F70ULL); }
            }
            // NOTE : Edit resource files only in Visual Studio.
            if (0 != LoadMenuResource(IDR_MENU1)) { exceptions(0x001AB1ULL); }
            if (0 != SetUseMenuFlag(TRUE)) { exceptions(0x001B90ULL); }
        }
        // Specified application title.
        str.clear();
        if (getParameter("$WINDOW_TEXT", &str)) {
            if (!str.empty()) {
                if (0 != DxLib::SetWindowText(str.c_str())) { exceptions(0x0013A0ULL); }
            }
        }

        /* ******* DxLib setup. ******* */
        if (0 != SetDoubleStartValidFlag(FALSE)) { exceptions(0x001490ULL); }
        // Initialize the DX-Library.
        if (0 != DxLib_Init()) { exceptions(0x0015F0ULL); }
        // Reserve a callback so that the DxLib_End function is always called when an error occurs.
        if (std::atexit((void(_cdecl*)())DxLib_End)) {
            NATIVE_MSG("std::atexit((void(_cdecl*)())DxLib_End)が失敗。");
            exceptions(0x0016F0ULL);
        }

        if (DxLib_IsInit()) {
            // NOTE : The fact that GetUseMenuFlag is true is proof that the window process is scanning in this run. Therefore, register the window handle.
            if (GetUseMenuFlag()) {
                xg_hWnd = GetMainWindowHandle();
                xg_DxLibWnd = (WNDPROC)GetWindowLongPtr(xg_hWnd, GWLP_WNDPROC);
                xg_hInstance = GetTaskInstance();
                if (!setAccelaratorCommand()) { return false; }
                if (!SetWindowLongPtr(xg_hWnd, GWLP_WNDPROC, (LONG_PTR)DefinitiveProc)) { exceptions(0x001CD0ULL); }
            }
            else {
                // NOTE : Automatically run the game program when in full screen mode. (because there is no menu bar)
                setAppsActiveFlag(true);
                NATIVE_MSG("全画面モードでゲームを開始できませんでした。");
                if (getStaticBindingFailureFlag()) { return false; }
            }
            // Apps default key set up.
            if (!input::defaultSetBindingSCon()) { return false; }
            (void)writeStatusLog("アプリエンジンの初期化処理を実行しました。");
            return true;
        }
        else {
            return false;
        }
    }


    void AppEngine::eventLoop(RunMode indicator) {
        // Do event loop of the main program sequence.
        while (!ProcessMessage() && !ClearDrawScreen() && !getStaticBindingFailureFlag() && device::updateAllStateKey() && this->Receptions(indicator)) {
            if (nullptr != sequence_) {
                // Begin the main program.
                period_ = sequence_->Service(period_);
                if (Evaluate::PROC_QUIT == period_) {
                    setAppsActiveFlag(false);
                }
                else if (Evaluate::PROC_FAILED == period_) {
                    setAppsActiveFlag(false);
                    break;
                }
                else {
                    // Evaluate::PROC_SUCCEED; continue;
                }
            }
        }
    }


    void AppEngine::Finalize(void) const {
        // Finalize the DX-Library.
        if (0 != DxLib_End()) {
            setStaticProcessCode(0x0017F0ULL, STATIC_ERR_DOMINATOR);
            return;
        }
        (void)writeStatusLog("アプリエンジンの終了処理を実行しました。");
    }

}  // namespace terminal