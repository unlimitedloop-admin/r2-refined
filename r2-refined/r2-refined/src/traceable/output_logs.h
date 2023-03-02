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
//      File name       : output_logs.h
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
 * output logs.header
**/



#ifndef _R2R_TRACEABLE_OUTPUT_LOGS_H_
#define _R2R_TRACEABLE_OUTPUT_LOGS_H_

/* INCLUDES */
// C++ SYSTEM HEADER
#include <string>
// PROJECT USING HEADER
#include "logclass.h"



/* SOURCES */
namespace traceable {

    /// <summary>
    /// Output infomation to a log file.
    /// </summary>
    /// <param name="body_text">Log bodies</param>
    /// <param name="head_title">Log titles</param>
    /// <param name="level">(Optional)Log levels with LogClass</param>
    /// <param name="log_filepath">(Optional)Output destination of log files</param>
    /// <returns>True or false, functions succeeded or failed</returns>
    bool writeStatusLog(std::string body_text, std::string head_title, LogClass level = default_prclog_level, std::string log_filepath = "");

    /// <summary>
    /// Output infomation to a log file.
    /// </summary>
    /// <param name="body_text">Log bodies</param>
    /// <param name="level">(Optional)Log levels with LogClass</param>
    /// <returns>True or false, functions succeeded or failed</returns>
    bool writeStatusLog(std::string body_text, LogClass level = default_prclog_level);

    /// <summary>
    /// Output information to a log file.
    /// </summary>
    /// <param name="body_text">Log bodies</param>
    /// <returns>True or false, functions succeeded or failed</returns>
    bool writeLog(std::string body_text);

    /// <summary>
    /// Output error to a log file.
    /// </summary>
    /// <param name="body_text">Log bodies</param>
    /// <param name="head_title">Log titles</param>
    /// <param name="level">(Optional)Log levels with LogClass</param>
    /// <param name="log_filepath">(Optional)Output destination of log files</param>
    /// <returns>True or false, functions succeeded or failed</returns>
    bool writeErrorLog(std::string body_text, std::string head_title, LogClass level = default_errlog_level, std::string log_filepath = "");

    /// <summary>
    /// Output error to a log file.
    /// </summary>
    /// <param name="body_text">Log bodies</param>
    /// <param name="level">(Optional)Log levels with LogClass</param>
    /// <returns>True or false, functions succeeded or failed</returns>
    bool writeErrorLog(std::string body_text, LogClass level = default_errlog_level);

}  // namespace traceable

#endif // !_R2R_TRACEABLE_OUTPUT_LOGS_H_