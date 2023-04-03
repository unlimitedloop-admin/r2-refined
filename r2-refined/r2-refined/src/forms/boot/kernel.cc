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
//      File name       : kernel.cc
//
//      Author          : u7
//
//      Last update     : 2023/04/03
//
//      File version    : 10
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * It is the system kernel structure that holds the center.
**/



/* INCLUDES */
// C++ SYSTEM HEADER
#include <string>
// GENERAL USING HEADER
#include <Windows.h>
// PROJECT USING HEADER
#include "src/forms/boot/hardware_check.h"
#include "src/exceptions/exception_handler.h"
#include "src/protocol/env_params.h"
#include "src/protocol/evaluation.h"
#include "src/protocol/process_code_hard.h"
#include "src/protocol/message_box.h"
#include "src/traceable/output_logs.h"
#include "src/traceable/log_filepath.h"
#include "src/forms/terminal/app_engine.h"



/* SOURCES */
namespace {

    /* Using namespace */
    using namespace protocol;
    using namespace traceable;



    auto internalExecutionSelect(LPTSTR command) {
        auto mode = RunMode::GENERAL_MODE;
        if (!lstrcmp(command, L"debug")) {
            mode = RunMode::DEBUG_MODE;
        }
        return mode;
    }


    bool sysInit(LPTSTR szcmdline) {
        std::wstring str;
        // Before running the system, it checks whether it satisfies the operation standards of the execution environment.
        if (!boot::checkingSystemInfo()) { return false; }

        // A 'mode' set GENERAL or DEBUG that application execute a mode.
        RunMode mode = internalExecutionSelect(szcmdline);
        
        // Load enviroment any parameters. env = 0 is get env params successful, 1 is ".env" was not found, or else bad read processing.
        auto env = loadParameterFromEnv();
        if (0 == env) {
            // Sets some system properties if starting the system in debug mode is selected.
            if (RunMode::DEBUG_MODE == mode && getParameter(L"$STREAM_OUTPUT_LOG_PATH", &str)) {
                setStreamLogFilePath(str);
            }
            if (RunMode::DEBUG_MODE == mode) {
                MSG_BOX(L"Start in debug mode.");
                _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);  // Enable the debug heap manager to manage allocated memory regions.
                (void)writeStatusLog(L"デバッグモードでシステムを開始します。", LogClass::LOG_LEVEL_OFF);
            }
        }
        else if (1 == env) {
            MSG_BOX(L"It doesn't find any environment variables, so it boots in economy mode.\r\nSee README.txt.");
        }
        else {
            return false;
        }

        (void)writeStatusLog(L"システムを起動します。");
        return true;
    }


    void sysIgnition(LPTSTR szcmdline) {
        // A 'mode' set GENERAL or DEBUG that application execute a mode.
        RunMode mode = internalExecutionSelect(szcmdline);
        terminal::AppEngine apps;
        if (apps.Initialize(mode)) {
            // begin event loop of this system.
            apps.eventLoop(mode);
        }
        apps.Finalize();
    }


    bool sysFin(void) {
        // If there is an error output, check for the least hexadecimal digit is not zero in the global processing code.
        if (0x000000ULL != (getStaticProcessCode() & 0x00000FULL)) {
            exceptions::ExceptionHandler ex;
            ex.throwException(false);
            (void)writeErrorLog(L"エミュレーションでエラーログが出力されています。\n", LogClass::LOG_LEVEL_OFF);
            (void)writeStatusLog(L"システムが強制中断されました。\n", LogClass::LOG_LEVEL_OFF);
            return false;
        }
        (void)writeStatusLog(L"システムを終了します。\n");
        return true;
    }

}  // plain namespace



namespace boot {

    bool Systems(LPTSTR cmdline) {
        setStaticProcessCode(0x00ULL, STATIC_PROC_CD);
        if (sysInit(cmdline)) {
            sysIgnition(cmdline);
        }
        return sysFin();
    }

}  // namespace boot