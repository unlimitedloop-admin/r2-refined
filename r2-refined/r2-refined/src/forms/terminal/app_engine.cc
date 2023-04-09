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
//      Last update     : 2023/04/09
//
//      File version    : 15
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
// PROJECT USING HEADER
#include "src/forms/device/keyboards_in.h"
#include "src/exceptions/exception_handler.h"
#include "src/protocol/evaluation.h"
#include "src/protocol/process_code_hard.h"
#include "src/traceable/output_logs.h"
#include "src/app/input/key_binding.h"
#include "src/app/sequence/cursor_pointer.h"
#include "src/app/sequence/cursor_simulator.h"
#include "src/app/sequence/cursor_driver.h"
#include "src/database/tables/TRN_APU_CHANNEL_ENABLED.h"



/* SOURCES */
namespace terminal {

    /* using namespace */
    using namespace protocol;
    using namespace traceable;


    /* local scopes */
    ResultSet   dev_mode = ResultSet::DISABLED;     // Development running mode of applications
    ResultSet   test_driver = ResultSet::DISABLED;  // Test driver running flag
    GAMEPROC    apps_active = false;                // Activation supervisor
    Activator   activator = Activator::DISABLED;    // Main program activator key



    void setAppsActiveFlag(bool flag) {
        if (flag != getAppActiveParameter()) {
            setAppActiveParameter(flag);
            if (getAppActiveParameter()) {
                if (ResultSet::ENABLED == test_driver) { setActivator(Activator::CHANGE_DRIVER); }
                else if (ResultSet::ENABLED == dev_mode) { setActivator(Activator::CHANGE_DEVELOPPROC); }
                else { setActivator(Activator::CHANGE_MAINPROC); }

                if (0 != DxLib::SetDrawScreen(DX_SCREEN_BACK)) {
                    setStaticProcessCode(0x0005B0LL, STATIC_ERR_DOMINATOR);
                    setStaticBindingFailureFlag(true);
                }
            }
            else {
                setActivator(Activator::NOT_ACTIVATION);
                if (0 != DxLib::SetDrawScreen(DX_SCREEN_FRONT)) {
                    setStaticProcessCode(0x0006B0LL, STATIC_ERR_DOMINATOR);
                    setStaticBindingFailureFlag(true);
                }
            }
        }
    }


    void setApplicationConfiguration(void) {
        DB::TRN_APU_CHANNEL_ENABLED::Insert(5U);   // SQ1, SQ2, TRI, NOI, DPCM (5)
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
        if (0 != DxLib::SetDoubleStartValidFlag(FALSE)) { exception_exit(0x001490ULL); }
        // Initialize the DX-Library.
        if (0 != DxLib::DxLib_Init()) { exception_exit(0x0015F0ULL); }
        // Reserve a callback so that the DxLib_End function is always called when an error occurs.
        std::atexit((void(_cdecl*)())DxLib::DxLib_End);

        if (DxLib::DxLib_IsInit()) {
            /* Registered client application. */
            if (!this->registeredClientSystem(exception_exit)) { return false; }
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
        while (!DxLib::ProcessMessage() && !DxLib::ScreenFlip() && !DxLib::ClearDrawScreen() && !getStaticBindingFailureFlag() && device::updateAllStateKey() && this->Receptions(indicator)) {
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
        if (0 != DxLib::DxLib_End()) {
            setStaticProcessCode(0x0017F0ULL, STATIC_ERR_DOMINATOR);
            return;
        }
        (void)writeStatusLog(L"アプリエンジンの終了処理を実行しました。");
    }

}  // namespace terminal