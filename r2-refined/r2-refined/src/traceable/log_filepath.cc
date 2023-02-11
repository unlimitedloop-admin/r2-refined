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
//      File name       : log_filepath.h
//
//      Author          : u7
//
//      Last update     : 2023/02/11
//
//      File version    : 1
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

    std::string stream_defaultlog = "";
    std::string stream_errorlog = "error.log";

    std::string createLogFileName(const std::string identifier) {
        std::string str;
        util_time::getCurrentDateTime(&str, "YYYYMMDD");
        str = str.substr(0, 6) + identifier + str + ".log";  // str.substr(0, 6) + "/" + is Monthly partition(Directory).
        return str;
    }

}  // plain namespace



namespace traceable {

    std::string getDefaultLogFilePath(void) {
        return stream_defaultlog;
    }


    std::string getErrorLogFilePath(void) {
        return stream_errorlog;
    }


    void setStreamLogFilePath(std::string dir_path) {
        if (!dir_path.empty()) {
            // logfile name is '<log_type>log_[YYYYMMDD].log'.
            stream_defaultlog = dir_path + createLogFileName("\\processlog_");
            stream_errorlog = dir_path + createLogFileName("\\errorlog_");
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