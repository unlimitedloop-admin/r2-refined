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
//      File name       : log_filepath.cc
//
//      Author          : u7
//
//      Last update     : 2023/04/03
//
//      File version    : 3
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * Make a log filepath.
**/



/* INCLUDES */
// C++ SYSTEM HEADER
#include <string>
// PROJECT USING HEADER
#include "src/util/time/systime.h"          /* UTILITY MODULES */



/* SOURCES */
namespace {

    std::wstring stream_defaultlog = L"";
    std::wstring stream_errorlog = L"error.log";

    std::wstring createLogFileName(const std::wstring identifier) {
        std::wstring str;
        util_time::getCurrentDateTime(&str, L"YYYYMMDD");
        str = str.substr(0, 6) + identifier + str + L".log";  // str.substr(0, 6) + "/" + is Monthly partition(Directory).
        return str;
    }

}  // plain namespace



namespace traceable {

    std::wstring getDefaultLogFilePath(void) {
        return stream_defaultlog;
    }


    std::wstring getErrorLogFilePath(void) {
        return stream_errorlog;
    }


    void setStreamLogFilePath(std::wstring dir_path) {
        if (!dir_path.empty()) {
            // logfile name is '<log_type>log_[YYYYMMDD].log'.
            stream_defaultlog = dir_path + createLogFileName(L"\\processlog_");
            stream_errorlog = dir_path + createLogFileName(L"\\errorlog_");
        }
    }


    bool existsLogFilePath(void) {
        if (stream_defaultlog.empty() && stream_errorlog.empty()) {
            return false;
        }
        else {
            return true;
        }
    }

}  // namespace traceable