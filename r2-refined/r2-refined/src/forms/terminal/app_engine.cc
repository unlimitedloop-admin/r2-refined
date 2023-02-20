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
//      Last update     : 2023/02/20
//
//      File version    : 3
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



/* SOURCES */
namespace {

    /* using namespace */
    using namespace protocol;
    using namespace traceable;


    /* using alias */
    using GAMEPROC = bool;


    /* local scopes */
    ResultSet   dev_mode = ResultSet::DISABLED; // Development running mode of applications
    GAMEPROC    apps_active;                    // Activation supervisor
    Activator   activator;                      // Main program activator key




    void setAppsActiveFlag(bool flag) {
        if (flag != apps_active) {
            apps_active = flag;
            if (apps_active) {
                if (ResultSet::ENABLED != dev_mode) { activator = Activator::CHANGE_MAINPROC; }
                else { activator = Activator::CHANGE_DEVELOPPROC; }

                if (0 != SetDrawScreen(DX_SCREEN_BACK)) { setStaticProcessCode(0x0005B0LL, STATIC_ERR_DOMINATOR); }
            }
            else {
                activator = Activator::NOT_ACTIVATION;
                if (0 != SetDrawScreen(DX_SCREEN_FRONT)) { setStaticProcessCode(0x0006B0LL, STATIC_ERR_DOMINATOR); }
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


    AppEngine::AppEngine() {
    }


    AppEngine::~AppEngine() {
    }


    bool AppEngine::Receptions(RunMode ticket) {
        switch (activator) {
        case Activator::NOT_ACTIVATION:
            (void)writeStatusLog("ゲームプログラムの運転を停止しました。");
            DxLib::SetBackgroundColor(0, 0, 0);   // ★ test code.
            activator = Activator::DISABLED;
            break;
        case Activator::CHANGE_MAINPROC:
            (void)writeStatusLog("ゲームプログラムの運転を開始しました。");
            DxLib::SetBackgroundColor(255, 255, 255);   // ★ test code.
            activator = Activator::DISABLED;
            break;
        case Activator::CHANGE_DEVELOPPROC:
            (void)writeStatusLog("ゲームプログラムの運転を開始しました。[DEVELOPMENT MODE IS ENABLED]");
            DxLib::SetBackgroundColor(255, 255, 255);   // ★ test code.
            activator = Activator::DISABLED;
            break;
        case Activator::DISABLED:
            break;
        default:
            setStaticProcessCode(0x0011B1ULL, STATIC_ERR_DOMINATOR);
            NATIVE_MSG("#Activator: %d", static_cast<int>(activator));
            return false;
        }
        return true;
    }


    bool AppEngine::Initialize(RunMode indicator) const {
        std::string str;
        
        /* ******* Pick up an environment variable and set up its value in this system. ******* */
        // Check for development mode flag. (For development, normally 0)
        str.clear();
        if (getParameter("$DEV_MODE", &str)) {
            if ("1" == str) {
                dev_mode = ResultSet::ENABLED;
                (void)writeStatusLog("システムはデヴェロップメントモードで開始されます。", LogClass::LOG_LEVEL_OFF);
            }
        }
        // Output DxLib log. Specify the output destination of the DxLib exclusive log before calling the DxLib function. 
        if (RunMode::GENERAL_MODE == indicator) {
            if (0 != SetOutApplicationLogValidFlag(FALSE)) { setStaticProcessCode(0x000771ULL, STATIC_ERR_DOMINATOR); }
        }
        else {
            if (getParameter("$DXLIB_OUTPUT_LOG_PATH", &str)) {
                if (0 != SetApplicationLogSaveDirectory(str.c_str())) { setStaticProcessCode(0x000871ULL, STATIC_ERR_DOMINATOR); }
            }
        }
        // Active (or inactive) window always running application.
        str.clear();
        if (getParameter("$WINDOW_ALWAYS_RUN_ENABLED", &str)) {
            if ("1" == str) {
                if (0 != SetAlwaysRunFlag(TRUE)) { setStaticProcessCode(0x000951ULL, STATIC_ERR_DOMINATOR); }
            }
            else {
                if (0 != SetAlwaysRunFlag(FALSE)) { setStaticProcessCode(0x000A51ULL, STATIC_ERR_DOMINATOR); }
            }
        }
        // Screen setup.
        str.clear();
        (void)getParameter("$WINDOW_MODE_ENABLED", &str);
        if ("0" == str) {
            if (DX_CHANGESCREEN_OK != ChangeWindowMode(FALSE)) {
                setStaticProcessCode(0x000BF1ULL, STATIC_ERR_DOMINATOR);
                return false;
            }
            if (0 != SetUseMenuFlag(FALSE)) { setStaticProcessCode(0x000C91ULL, STATIC_ERR_DOMINATOR); }
        }
        else {
            // Default route.
            if (DX_CHANGESCREEN_OK != ChangeWindowMode(TRUE)) {
                setStaticProcessCode(0x000DF1ULL, STATIC_ERR_DOMINATOR);
                return false;
            }
            if (0 != SetWindowPosition(10, 10)) { setStaticProcessCode(0x000E71ULL, STATIC_ERR_DOMINATOR); }
            str.clear();
            if (getParameter("$WINDOW_EXTEND_RATE", &str)) {
                double rate;
                if (!str.empty() && util_conv::tryParseStrToDouble(&rate, str)) {
                    if (0 != SetWindowSizeExtendRate(rate)) { setStaticProcessCode(0x000F70ULL, STATIC_ERR_DOMINATOR); }
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
                    if (DX_CHANGESCREEN_OK != SetGraphMode(256, 240, 16)) {
                        setStaticProcessCode(0x0012F1ULL, STATIC_ERR_DOMINATOR);
                        return false;
                    }
                }
            }
            else {
                if (DX_CHANGESCREEN_OK != SetGraphMode(256, 240, 16)) {
                    setStaticProcessCode(0x0012F1ULL, STATIC_ERR_DOMINATOR);
                    return false;
                }
                if (0 != SetWindowSizeExtendRate(1.0)) { setStaticProcessCode(0x000F70ULL, STATIC_ERR_DOMINATOR); }
            }
            // NOTE : Edit resource files only in Visual Studio.
            if (0 != LoadMenuResource(IDR_MENU1)) {
                setStaticProcessCode(0x001AB1ULL, STATIC_ERR_DOMINATOR);
                return false;
            }
            if (0 != SetUseMenuFlag(TRUE)) { setStaticProcessCode(0x001B90ULL, STATIC_ERR_DOMINATOR); }
        }
        // Specified application title.
        str.clear();
        if (getParameter("$WINDOW_TEXT", &str)) {
            if (!str.empty()) {
                if (0 != DxLib::SetWindowText(str.c_str())) {
                    setStaticProcessCode(0x0013A0ULL, STATIC_ERR_DOMINATOR);
                    return false;
                }
            }
        }

        /* ******* DxLib setup. ******* */
        if (0 != SetDoubleStartValidFlag(FALSE)) {
            setStaticProcessCode(0x001490ULL, STATIC_ERR_DOMINATOR);
            return false;
        }
        // Initialize the DX-Library.
        if (0 != DxLib_Init()) {
            setStaticProcessCode(0x0015F0ULL, STATIC_ERR_DOMINATOR);
            return false;
        }
        // Reserve a callback so that the DxLib_End function is always called when an error occurs.
        if (std::atexit((void(_cdecl*)())DxLib_End)) {
            setStaticProcessCode(0x0016F0ULL, STATIC_ERR_DOMINATOR);
            NATIVE_MSG("std::atexit((void(_cdecl*)())DxLib_End)が失敗。");
            return false;
        }

        if (DxLib_IsInit()) {
            // NOTE : The fact that GetUseMenuFlag is true is proof that the window process is scanning in this run. Therefore, register the window handle.
            if (GetUseMenuFlag()) {
                xg_hWnd = GetMainWindowHandle();
                xg_DxLibWnd = (WNDPROC)GetWindowLongPtr(xg_hWnd, GWLP_WNDPROC);
                xg_hInstance = GetTaskInstance();
                if (!setAccelaratorCommand()) { return false; }
                if (!SetWindowLongPtr(xg_hWnd, GWLP_WNDPROC, (LONG_PTR)DefinitiveProc)) { setStaticProcessCode(0x001CD0ULL, STATIC_ERR_DOMINATOR); }
            }
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
            // TODO : Please describe the sequencer controlling from here. >>>








            if (0 != DxLib::ScreenFlip()) { break; }
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