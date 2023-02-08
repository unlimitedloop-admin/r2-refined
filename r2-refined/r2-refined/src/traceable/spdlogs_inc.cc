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
//      File name       : spdlogs_inc.cc
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
 * Build an original log output mechanism using the spdlog library.
**/



/* INCLUDES */
// C++ SYSTEM HEADER
#include <sstream>
#include <string>
// GENERAL USING HEADER
#include <Windows.h>
#include <spdlog.h>
#include <sinks/basic_file_sink.h>
// PROJECT USING HEADER
#include "logclass.h"



/* SOURCES */
namespace traceable {

    bool doOutputSpdlog(std::string path, std::string title, std::string body, LogClass level) {
        try {
            auto i_logger = spdlog::basic_logger_mt(title, path);
            switch (level) {
            case LogClass::LOG_LEVEL_TRACE:
                spdlog::set_level(spdlog::level::trace);
                i_logger->trace(body);
                break;
            case LogClass::LOG_LEVEL_DEBUG:
                spdlog::set_level(spdlog::level::debug);
                i_logger->debug(body);
                break;
            case LogClass::LOG_LEVEL_INFO:
                i_logger->info(body);
                break;
            case LogClass::LOG_LEVEL_WARN:
                i_logger->warn(body);
                break;
            case LogClass::LOG_LEVEL_ERROR:
                i_logger->error(body);
                break;
            case LogClass::LOG_LEVEL_CRITICAL:
                i_logger->critical(body);
                break;
            default:
                i_logger->log(spdlog::level::off, body);
                break;
            }
            spdlog::drop(title);
        }
        catch (const spdlog::spdlog_ex& ex) {
            std::stringstream ss;
            ss << "Log init failure: " << ex.what() << std::string("\0");
            std::string exstr = ss.str();
            MessageBox(NULL, exstr.c_str(), "spdlog Exception info", MB_OK);
            return false;
        }
        return true;
    }

}  // namespace traceable