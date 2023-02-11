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
//      Last update     : 2023/02/11
//
//      File version    : 3
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
#include "src/traceable/output_logs.h"
#include "src/traceable/log_filepath.h"



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
        // A 'mode' set GENERAL or DEBUG that application execute a mode.
        RunMode mode = internalExecutionSelect(szcmdline);
        // Load enviroment any parameters.
        auto env = loadParameterFromEnv();
        std::string str;
        if (0 == env) {
            if (RunMode::DEBUG_MODE == mode && getParameter("$STREAM_OUTPUT_LOG_PATH", &str)) {
                traceable::setStreamLogFilePath(str);
            }
            if (RunMode::DEBUG_MODE == mode && getParameter("$MESSAGE_BOX_LABELS", &str)) {
                MessageBox(NULL, "Start in debug mode.", str.c_str(), MB_OK);   // TODO : Make function.
                (void)traceable::writeStatusLog("デバッグモードでシステムを開始します。");
            }
        }
        (void)traceable::writeStatusLog("システムを起動します。");
        return true;
    }


    void Ignition(LPSTR szcmdline) {
    }


    bool sysFin(void) {
        (void)traceable::writeStatusLog("システムを終了します。\n");
        return true;
    }

}  // plain namespace



namespace boot {

    bool Systems(LPSTR cmdline) {
        if (sysInit(cmdline)) {
            Ignition(cmdline);
        }
        return sysFin();
    }

}  // namespace boot