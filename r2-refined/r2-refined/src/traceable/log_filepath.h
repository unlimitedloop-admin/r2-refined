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
 * log filepath.header
**/



#ifndef _R2R_TRACEABLE_LOG_FILEPATH_H_
#define _R2R_TRACEABLE_LOG_FILEPATH_H_

/* INCLUDES */
// C++ SYSTEM HEADER
#include <string>



/* SOURCES */
namespace traceable {

    /// <summary>
    /// Get the log process log file path.
    /// </summary>
    /// <param name="">Void</param>
    /// <returns>Log filepath</returns>
    std::wstring getDefaultLogFilePath(void);

    /// <summary>
    /// Get the log file path of error.
    /// </summary>
    /// <param name="">Void</param>
    /// <returns>Errorlog filepath</returns>
    std::wstring getErrorLogFilePath(void);

    /// <summary>
    /// Generate the log file storage location.
    /// </summary>
    /// <param name="dir_path">Common directory path</param>
    void setStreamLogFilePath(std::wstring dir_path);

    /// <summary>
    /// Whether the log file path has been set.
    /// </summary>
    /// <param name="">Void</param>
    /// <returns>Returns true if the log filepath is set</returns>
    bool existsLogFilePath(void);

}  // namespace traceable

#endif // !_R2R_TRACEABLE_LOG_FILEPATH_H_