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
//      Last update     : 2023/04/08
//
//      File version    : 14
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
#include "resource.h"
#include "src/app/input/key_binding.h"
#include "src/app/sequence/cursor_pointer.h"
#include "src/app/sequence/cursor_simulator.h"
#include "src/app/sequence/cursor_driver.h"
#include "src/database/tables/TRN_APU_CHANNEL_ENABLED.h"



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
    GAMEPROC    apps_active = false;                // Activation supervisor
    Activator   activator = Activator::DISABLED;    // Main program activator key




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


    void setApplicationConfiguration(void) {
        DB::TRN_APU_CHANNEL_ENABLED::Insert(5U);   // SQ1, SQ2, TRI, NOI, DPCM (5)
    }

}  // local scope



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


    bool AppEngine::Receptions(RunMode ticket) {
        switch (activator) {
        case Activator::NOT_ACTIVATION:
            if (nullptr != sequence_) {
                delete sequence_;
                sequence_ = nullptr;
                (void)writeStatusLog(L"ゲームプログラムの運転を停止しました。");
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
            NATIVE_MSG(L"#Activator: %d", static_cast<int>(activator));
            return false;
        }
        activator = Activator::DISABLED;
        return true;
    }


    bool AppEngine::Initialize(RunMode indicator) {
        std::wstring str;
        auto exception_exit = [](unsigned __int64 code) { setStaticProcessCode(code, STATIC_ERR_DOMINATOR); return false; };

        /* ******* Pick up an environment variable and set up its value in this system. ******* */
        if (!this->runmodeChoice(indicator, test_driver, dev_mode, exception_exit)) { return false; }

        /* ******* Set up the application screen configuration. ******* */
        if (!this->runInBackground(exception_exit)) { return false; }

        /* ******* Window configurations. ******* */
        if (!this->setWindowConfigs(exception_exit)) { return false; }

        /* ******* DxLib setup. ******* */
        if (0 != SetDoubleStartValidFlag(FALSE)) { exception_exit(0x001490ULL); }
        // Initialize the DX-Library.
        if (0 != DxLib_Init()) { exception_exit(0x0015F0ULL); }
        // Reserve a callback so that the DxLib_End function is always called when an error occurs.
        if (std::atexit((void(_cdecl*)())DxLib_End)) {
            NATIVE_MSG(L"std::atexit((void(_cdecl*)())DxLib_End)が失敗。");
            exception_exit(0x0016F0ULL);
        }

        if (DxLib_IsInit()) {
            // NOTE : The fact that GetUseMenuFlag is true is proof that the window process is scanning in this run. Therefore, register the window handle.
            if (GetUseMenuFlag()) {
                xg_hWnd = GetMainWindowHandle();
                xg_DxLibWnd = (WNDPROC)GetWindowLongPtr(xg_hWnd, GWLP_WNDPROC);
                xg_hInstance = GetTaskInstance();
                if (!setAccelaratorCommand()) { return false; }
                if (!SetWindowLongPtr(xg_hWnd, GWLP_WNDPROC, (LONG_PTR)DefinitiveProc)) { exception_exit(0x001CD0ULL); }
            }
            else {
                // NOTE : Automatically run the game program when in full screen mode. (because there is no menu bar)
                setAppsActiveFlag(true);
                NATIVE_MSG(L"全画面モードでゲームを開始できませんでした。");
                if (getStaticBindingFailureFlag()) { return false; }
            }
            // Apps default key set up.
            if (!input::defaultSetBindingSCon()) { return false; }
            
            // Set application config.
            setApplicationConfiguration();
            (void)writeStatusLog(L"アプリエンジンの初期化処理を実行しました。");
            return true;
        }
        else {
            return false;
        }
    }


    void AppEngine::eventLoop(RunMode indicator) {
        // Do event loop of the main program sequence.
        while (!ProcessMessage() && !ScreenFlip() && !ClearDrawScreen() && !getStaticBindingFailureFlag() && device::updateAllStateKey() && this->Receptions(indicator)) {
            if (nullptr != sequence_) {
                // Begin the main program.
                /*
                 * >>> sequence_ = CursorPointer defaults to the main program when executed.
                 * >>> sequence_ = CursorSimulator provides a backdoor menu for development.
                 * >>> sequence_ = CursorDriver are not normally used. It's a laboratory table when you do temporary program testing.
                 */
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


    void AppEngine::Finalize(void) {
        if (nullptr != sequence_) {
            delete sequence_;
            sequence_ = nullptr;
        }
        // Finalize the DX-Library.
        if (0 != DxLib_End()) {
            setStaticProcessCode(0x0017F0ULL, STATIC_ERR_DOMINATOR);
            return;
        }
        (void)writeStatusLog(L"アプリエンジンの終了処理を実行しました。");
    }

}  // namespace terminal