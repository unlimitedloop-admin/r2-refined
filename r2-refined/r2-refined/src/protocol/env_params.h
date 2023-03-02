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
//      File name       : env_params.h
//
//      Author          : u7
//
//      Last update     : 2023/02/09
//
//      File version    : 1
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * env params.header
**/



#ifndef _R2R_PROTOCOL_ENV_PARAMS_H_
#define _R2R_PROTOCOL_ENV_PARAMS_H_

/* INCLUDES */
// C++ SYSTEM HEADER
#include <string>



/* SOURCES */
namespace protocol {

    /// <summary>
    /// Load the environment variable file into memory.
    /// </summary>
    /// <param name="file_path">Environment file path</param>
    /// <returns>Return zero if successful, others fails</returns>
    __int8 loadParameterFromEnv(const char* file_path = ".env");

    /// <summary>
    /// Gets the environment variable with the specified variable label.
    /// </summary>
    /// <param name="label">Variable labels</param>
    /// <param name="byref_args">A reference argument to store the variable</param>
    /// <returns>The return value will be true if the value is stored in the reference pointer, others false</returns>
    bool getParameter(const char* label, std::string* byref_args);

    /// <summary>
    /// Check if environment variable exists.
    /// </summary>
    /// <param name="">Void</param>
    /// <returns>Exists is true, empty is false</returns>
    bool existsEnvParams(void);

}  // namespace protocol

#endif // !_R2R_PROTOCOL_ENV_PARAMS_H_