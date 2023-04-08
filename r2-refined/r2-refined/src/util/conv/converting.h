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
//      Last update     : 2023/04/08
//
//      File version    : 4
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
    /// Converts a string type array to the Windows-specific const wchar_t pointer.
    /// </summary>
    /// <param name="expression">Expression for wchar_t type string</param>
    /// <returns>Converted LPCWSTR for expression</returns>
    const wchar_t* wcharToConstWchar(wchar_t* expression);

    /// <summary>
    /// Converts a 1byte char array to the Windows-specific const wchar_t pointer.
    /// </summary>
    /// <param name="expression">Expression for char type string</param>
    /// <returns>Converted LPCWSTR for expression</returns>
    std::wstring charToWstring(const char* expression);

    /// <summary>
    /// Try converting a string to a number of integer type.
    /// </summary>
    /// <param name="byref">A Integer-type reference address</param>
    /// <param name="num_str">Target of converting</param>
    /// <returns>Returns true if successful</returns>
    bool tryParseStrToInt(int* byref, std::wstring num_str);

    /// <summary>
    /// Try converting a string to a number of double type.
    /// </summary>
    /// <param name="byref">A Double-type reference address</param>
    /// <param name="num_str">Target of converting</param>
    /// <returns>Returns true if successful</returns>
    bool tryParseStrToDouble(double* byref, std::wstring num_str);

}  // namespace util_conv

// DEFINE MACROS
#define WCHAR_TO_LPCWSTR(expr) util_conv::wcharToConstWchar(expr)
#define CHAR_TO_WSTRING(expr) util_conv::charToWstring(expr)

#endif // !_R2R_UTIL_CONV_CONVERTING_H_