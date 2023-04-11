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
//      File name       : app_engine_set_activation.cc
//
//      Author          : u7
//
//      Last update     : 2023/04/11
//
//      File version    : 1
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * The main game engine at the core of this application. (Partial divided)
**/



/* INCLUDES */
// PRIMARY HEADER
#include "app_engine.h"
// GENERAL USING HEADER
#include <DxLib.h>
// PROJECT USING HEADER
#include "src/protocol/evaluation.h"
#include "src/protocol/process_code_hard.h"
#include "src/exceptions/exception_handler.h"
#include "src/traceable/output_logs.h"
#include "src/app/sequence/cursor_pointer.h"
#include "src/app/sequence/cursor_simulator.h"
#include "src/app/sequence/cursor_driver.h"



/* SOURCES */
namespace {

    /* using alias */
    using GAMEPROC = bool;

    /* local scopes */
    GAMEPROC    apps_active = false;    // Activation supervisor

}


namespace terminal {

    /* using namespace */
    using namespace traceable;


    bool AppEngine::Receptions(RunMode ticket) {
        switch (getActivator()) {
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
            NATIVE_MSG(L"#Activator: %d", static_cast<int>(getActivator()));
            return false;
        }
        setActivator(Activator::DISABLED);
        return true;
    }


    void setAppsActiveFlag(bool flag) {
        if (flag != apps_active) {
            apps_active = flag;
            if (apps_active) {
                switch (programs) {
                case Simulator::MAIN_PROGRAM:
                    setActivator(Activator::CHANGE_MAINPROC);
                    break;
                case Simulator::DEVELOPER:
                    setActivator(Activator::CHANGE_DEVELOPPROC);
                    break;
                case Simulator::TEST_DRIVER:
                    setActivator(Activator::CHANGE_DRIVER);
                    break;
                default:
                    setActivator(Activator::NOT_ACTIVATION);
                    break;
                }

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

}  // namespace terminal