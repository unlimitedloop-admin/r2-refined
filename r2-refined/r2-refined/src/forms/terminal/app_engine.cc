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
//      Last update     : 2023/04/29
//
//      File version    : 19
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
#include "src/protocol/evaluation.h"
#include "src/protocol/process_code_hard.h"
#include "src/traceable/output_logs.h"
#include "src/app/input/key_binding.h"
#include "src/database/triggers/NEW_APPLICATION_STARTUP.h"



/* SOURCES */
namespace terminal {

    /* using namespace */
    using namespace protocol;
    using namespace traceable;

    /* local scopes */
    Activator activator = Activator::DISABLED;  // Main program activator key
    Simulator programs = Simulator::OFF;        // Program routes



    bool AppEngine::Initialize(RunMode indicator) {
        std::wstring str;
        auto exception_exit = [](unsigned __int64 code) { setStaticProcessCode(code, STATIC_ERR_DOMINATOR); return false; };

        /* ******* Pick up an environment variable and set up its value in this system. ******* */
        if (!this->runmodeChoice(indicator, programs, exception_exit)) { return false; }

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
            DB::TRIGGER::NEW_APPLICATION_STARTUP();
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
                 * The value of sequence_ is set by the activator key, and the process is controlled by the 'AppEngine::Receptions' method.
                 */
                period_ = sequence_->Service(period_);
                if (Evaluate::PROC_QUIT == period_) {
                    setAppsActiveFlag(false);   // Stop the main program.
                }
                else if (Evaluate::PROC_FAILED == period_) {
                    setAppsActiveFlag(false);   // Stop the main program and force the system to terminate (ie, abort).
                    break;
                }
                else {}
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


    void setActivator(Activator value) {
        activator = value;
    }


    Activator getActivator(void) {
        return activator;
    }

}  // namespace terminal