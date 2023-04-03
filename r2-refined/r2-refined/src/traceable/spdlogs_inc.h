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
//      File name       : spdlogs_inc.h
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
 * spdlogs inc.header
**/



#ifndef _R2R_TRACEABLE_SPDLOGS_INC_H_
#define _R2R_TRACEABLE_SPDLOGS_INC_H_

/* INCLUDES */
// C++ SYSTEM HEADER
#include <string>
// PROJECT USING HEADER
#include "logclass.h"
// define macros
#define SPDLOG_EOL "\n"



/* SOURCES */
namespace traceable {

    /// <summary>
    /// Logstream using the spdlog library.
    /// </summary>
    /// <param name="path">Output destination</param>
    /// <param name="title">Log titles</param>
    /// <param name="body">Log contents</param>
    /// <param name="level">Log levels with LogClass</param>
    /// <returns>True or false, functions succeeded or failed</returns>
    bool doOutputSpdlog(std::wstring path, std::string title, std::wstring body, LogClass level);

}  // namespace traceable

#endif // !_R2R_TRACEABLE_SPDLOGS_INC_H_