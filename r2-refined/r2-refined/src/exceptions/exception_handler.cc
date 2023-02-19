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
//      File name       : exception_handler.cc
//
//      Author          : u7
//
//      Last update     : 2023/02/19
//
//      File version    : 2
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * Throw handler for exception processing.
**/



/* INCLUDES */
// PRIMARY HEADER
#include "exception_handler.h"
// PROJECT USING HEADER
#include "src/protocol/xglobals.h"
#include "src/protocol/process_code_hard.h"
#include "src/traceable/logclass.h"
#include "src/traceable/output_logs.h"
#include "src/util/logic/reference.h"       /* UTILITY MODULES */
/* ErrorLists */
#include "error/errorlist_0x00x.h"
#include "error/errorlist_0x01x.h"



/* SOURCES */
namespace exceptions {

    /* using namespace */
    using namespace traceable;



    ExceptionHandler::ExceptionHandler() {
        creature_ = nullptr;
        msg_ = "";
    }


    ExceptionHandler::~ExceptionHandler() {
        if (nullptr != creature_) {
            delete creature_;
            creature_ = nullptr;
        }
    }


    void ExceptionHandler::throwException(bool abend) {
        if (nullptr != creature_) {
            delete creature_;
            creature_ = nullptr;
        }

        LogClass level;
        auto error_code = getStaticProcessCode();
        switch (error_code & 0x0000F0ULL) {
        case 0x00:
            level = LogClass::LOG_LEVEL_UNKNOWN;
            break;
        case 0x10:
            level = LogClass::LOG_LEVEL_TRACE;
            break;
        case 0x20:
            level = LogClass::LOG_LEVEL_DEBUG;
            break;
        case 0x30:
        case 0x40:
        case 0x50:
        case 0x60:
            level = LogClass::LOG_LEVEL_INFO;
            break;
        case 0x70:
        case 0x80:
        case 0x90:
        case 0xA0:
            level = LogClass::LOG_LEVEL_WARN;
            setStaticBindingFailureFlag(true);
            break;
        case 0xB0:
        case 0xC0:
        case 0xD0:
        case 0xE0:
            level = LogClass::LOG_LEVEL_ERROR;
            setStaticBindingFailureFlag(true);
            break;
        case 0xF0:
            level = LogClass::LOG_LEVEL_CRITICAL;
            setStaticBindingFailureFlag(true);
            break;
        default:
            level = LogClass::LOG_LEVEL_UNKNOWN;
            break;
        }
        if (util_logic::Between(error_code / 0x000100ULL, 0x0001ULL, 0x00FFULL)) {
            creature_ = new ErrorList0x00x;
            msg_ = creature_->Major(error_code, level);
        }
        else if (util_logic::Between(error_code / 0x000100ULL, 0x0101ULL, 0x01FFULL)) {
            creature_ = new ErrorList0x01x;
            msg_ = creature_->Major(error_code, level);
        }
        if (!msg_.empty()) { MessageBox(xg_hWnd, msg_.c_str(), "エラー通知", MB_OK); }

        if (!xg_nMsg.empty()) {
            (void)writeErrorLog(xg_nMsg, "NATIVE MSG", level);     // Go output error log.
            xg_nMsg.clear();
        }
        // If a system exception message is received, print that message.
        if (!xg_exChar.empty()) {
            MessageBox(xg_hWnd, xg_exChar.c_str(), "例外詳細", MB_OK);
            (void)writeErrorLog(xg_exChar, "EXCEPTION TRACEABILITY", level);     // Go output error log.
            xg_exChar.clear();
        }
        if (abend) { setStaticBindingFailureFlag(true); }  // The flag conversion for abend bookmarks.
    }

}  // namespace exceptions