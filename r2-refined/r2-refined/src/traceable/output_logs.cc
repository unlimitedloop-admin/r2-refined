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
//      File name       : output_logs.cc
//
//      Author          : u7
//
//      Last update     : 2023/04/03
//
//      File version    : 2
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * This source code will be used when outputting logs in this project.
 * The "spdlog" library is used for log output.
**/



 /* INCLUDES */
 // C++ SYSTEM HEADER
#include <string>
// PROJECT USING HEADER
#include "spdlogs_inc.h"
#include "log_filepath.h"
#include "logclass.h"



/* SOURCES */
namespace {

    bool putLightLog(std::wstring log_filepath, std::wstring body_text, std::string head_title, traceable::LogClass levels) {
        if (log_filepath.empty()) { return false; }
        return traceable::doOutputSpdlog(log_filepath, head_title, body_text, levels);
    }

}  // plain namespace



namespace traceable {

    // FIXME : Some methods of spdlog cannot handle wide type strings. So this argument 'title' is just thrown away.
    bool writeStatusLog(std::wstring body_text, std::wstring head_title, LogClass level, std::wstring log_filepath) {
        if (head_title.empty()) { return false; }
        std::wstring str = log_filepath;
        if (str.empty()) { str = getDefaultLogFilePath(); }
        if (!putLightLog(str, body_text, "process-log", level)) { return false; }
        return true;
    }


    bool writeStatusLog(std::wstring body_text, LogClass level) {
        std::wstring str = getDefaultLogFilePath();
        if (!putLightLog(str, body_text, "process-log", level)) { return false; }
        return true;
    }


    bool writeLog(std::wstring body_text) {
        std::wstring str = getDefaultLogFilePath();
        if (!putLightLog(str, body_text, "process-log", default_prclog_level)) { return false; }
        return true;
    }


    bool writeErrorLog(std::wstring body_text, std::wstring head_title, LogClass level, std::wstring log_filepath) {
        if (head_title.empty()) { return false; }
        std::wstring str = log_filepath;
        if (str.empty()) { str = getErrorLogFilePath(); }
        if (!putLightLog(str, body_text, "error-log", level)) { return false; }
        return true;
    }


    bool writeErrorLog(std::wstring body_text, LogClass level) {
        std::wstring str = getErrorLogFilePath();
        if (!putLightLog(str, body_text, "error-log", level)) { return false; }
        return true;
    }

}  // namespace traceable