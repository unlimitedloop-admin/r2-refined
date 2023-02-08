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
//      Last update     : 2023/02/08
//
//      File version    : 1
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
// GENERAL USING HEADER
#include <Windows.h>
// PROJECT USING HEADER
#include "src/protocol/evaluation.h"
#include "src/traceable/spdlogs_inc.h"



/* SOURCES */
namespace {

    /* Using namespace */
    using namespace protocol;



    auto executiveMandate(LPSTR command) {
        auto mode = RunMode::GENERAL_MODE;
        if (!lstrcmp(command, "debug")) {
            mode = RunMode::DEBUG_MODE;
        }
        return mode;
    }


    bool sysInit(LPSTR szcmdline) {
        // A 'mode' set GENERAL or DEBUG that application execute a mode.
        RunMode mode = executiveMandate(szcmdline);

        if (RunMode::DEBUG_MODE == mode) {
            MessageBox(NULL, "Start in debug mode.", "R2 Refined", MB_OK);
        }
        traceable::doOutputSpdlog("storages/traceability/str/default.log", "trace-log", "sysInit was finish.", traceable::LogClass::LOG_LEVEL_TRACE);
        return true;
    }


    void Ignition(LPSTR szcmdline) {
    }


    bool sysFin(void) {
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