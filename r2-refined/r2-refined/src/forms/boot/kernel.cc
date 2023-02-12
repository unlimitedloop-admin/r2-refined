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
//      Last update     : 2023/02/12
//
//      File version    : 4
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
#include "src/protocol/evaluation.h"
#include "src/protocol/env_params.h"
#include "src/protocol/message_box.h"
#include "src/traceable/output_logs.h"
#include "src/traceable/log_filepath.h"
#include "src/forms/boot/hardware_check.h"



/* SOURCES */
namespace {

    /* Using namespace */
    using namespace protocol;



    auto internalExecutionSelect(LPSTR command) {
        auto mode = RunMode::GENERAL_MODE;
        if (!lstrcmp(command, "debug")) {
            mode = RunMode::DEBUG_MODE;
        }
        return mode;
    }


    bool sysInit(LPSTR szcmdline) {
        std::string str;
        // Before running the system, it checks whether it satisfies the operation standards of the execution environment.
        if (!boot::checkingSystemInfo()) { return false; }

        // A 'mode' set GENERAL or DEBUG that application execute a mode.
        RunMode mode = internalExecutionSelect(szcmdline);
        
        // Load enviroment any parameters. env = 0 is get env params successful, 1 is ".env" was not found, or else bad read processing.
        auto env = loadParameterFromEnv();
        if (0 == env) {
            if (RunMode::DEBUG_MODE == mode && getParameter("$STREAM_OUTPUT_LOG_PATH", &str)) {
                traceable::setStreamLogFilePath(str);
            }
            if (RunMode::DEBUG_MODE == mode) {
                MSG_BOX("Start in debug mode.");
                (void)traceable::writeStatusLog("デバッグモードでシステムを開始します。");
            }
        }
        else if (1 == env) {
            MessageBox(NULL, "It doesn't find any environment variables, so it boots in economy mode.\r\nSee README.txt.", "r2refined", MB_OK);
        }
        else {
            // TODO : Error exception.
            return false;
        }

        (void)traceable::writeStatusLog("システムを起動します。");
        return true;
    }


    void sysIgnition(LPSTR szcmdline) {
        // promotions. >>>
        //auto a = 100;
        //auto b = 50;
        //PF_MSG_BOX("%d + %d = %dです。", a, b, a + b);
    }


    bool sysFin(void) {
        (void)traceable::writeStatusLog("システムを終了します。\n");
        return true;
    }

}  // plain namespace



namespace boot {

    bool Systems(LPSTR cmdline) {
        if (sysInit(cmdline)) {
            sysIgnition(cmdline);
        }
        return sysFin();
    }

}  // namespace boot