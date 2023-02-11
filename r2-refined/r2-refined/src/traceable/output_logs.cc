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

    bool putLightLog(std::string log_filepath, std::string body_text, std::string head_title, traceable::LogClass levels) {
        if (log_filepath.empty()) { return false; }
        return traceable::doOutputSpdlog(log_filepath, head_title, body_text, levels);
    }

}  // plain namespace



namespace traceable {

    bool writeStatusLog(std::string body_text, std::string head_title, LogClass level, std::string log_filepath) {
        if (head_title.empty()) { return false; }
        std::string str = log_filepath;
        if (str.empty()) { str = getDefaultLogFilePath(); }
        if (!putLightLog(str, body_text, head_title, level)) { return false; }
        return true;
    }


    bool writeStatusLog(std::string body_text, LogClass level) {
        std::string str = getDefaultLogFilePath();
        if (!putLightLog(str, body_text, "処理ログ", level)) { return false; }
        return true;
    }


    bool writeLog(std::string body_text) {
        std::string str = getDefaultLogFilePath();
        if (!putLightLog(str, body_text, "処理ログ", default_prclog_level)) { return false; }
        return true;
    }


    bool writeErrorLog(std::string body_text, std::string head_title, LogClass level, std::string log_filepath) {
        if (head_title.empty()) { return false; }
        std::string str = log_filepath;
        if (str.empty()) { str = getErrorLogFilePath(); }
        if (!putLightLog(str, body_text, head_title, level)) { return false; }
        return true;
    }


    bool writeErrorLog(std::string body_text, LogClass level) {
        std::string str = getErrorLogFilePath();
        if (!putLightLog(str, body_text, "エラーログ", level)) { return false; }
        return true;
    }

}  // namespace traceable