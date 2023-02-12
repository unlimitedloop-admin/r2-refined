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
//      Last update     : 2023/02/12
//
//      File version    : 1
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
#include <Windows.h>



/* SOURCES */
namespace util_conv {

    /// <summary>
    /// Converts a string type array to the Windows-specific const char pointer.
    /// </summary>
    /// <param name="expression">Expression for char type string</param>
    /// <returns>Converted LPCSTR for expression</returns>
    const char* charToConstChar(char* expression);

}  // namespace util_conv

// DEFINE MACROS
#define CHAR_TO_LPCSTR(expr) util_conv::charToConstChar(expr)

#endif // !_R2R_UTIL_CONV_CONVERTING_H_