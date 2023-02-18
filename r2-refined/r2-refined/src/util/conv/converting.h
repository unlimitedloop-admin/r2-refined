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
//      File name       : converting.h
//
//      Author          : u7
//
//      Last update     : 2023/02/18
//
//      File version    : 2
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * converting.header
**/



#ifndef _R2R_UTIL_CONV_CONVERTING_H_
#define _R2R_UTIL_CONV_CONVERTING_H_

/* INCLUDES */
// C++ SYSTEM HEADER
#include <string>



/* SOURCES */
namespace util_conv {

    /// <summary>
    /// Converts a string type array to the Windows-specific const char pointer.
    /// </summary>
    /// <param name="expression">Expression for char type string</param>
    /// <returns>Converted LPCSTR for expression</returns>
    const char* charToConstChar(char* expression);

    /// <summary>
    /// Try converting a string to a number of integer type.
    /// </summary>
    /// <param name="byref">A Integer-type reference address</param>
    /// <param name="num_str">Target of converting</param>
    /// <returns>Returns true if successful</returns>
    bool tryParseStrToInt(int* byref, std::string num_str);

    /// <summary>
    /// Try converting a string to a number of double type.
    /// </summary>
    /// <param name="byref">A Double-type reference address</param>
    /// <param name="num_str">Target of converting</param>
    /// <returns>Returns true if successful</returns>
    bool tryParseStrToDouble(double* byref, std::string num_str);

}  // namespace util_conv

// DEFINE MACROS
#define CHAR_TO_LPCSTR(expr) util_conv::charToConstChar(expr)

#endif // !_R2R_UTIL_CONV_CONVERTING_H_