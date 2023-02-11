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
//      File name       : systime.h
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
 * systime.header
**/



#ifndef _R2R_UTIL_TIME_SYSTIME_H_
#define _R2R_UTIL_TIME_SYSTIME_H_

/* INCLUDES */
// C++ SYSTEM HEADER
#include <string>



/* SOURCES */
namespace util_time {

    /// <summary>
    /// Get the current date time in the specified format.
    /// </summary>
    /// <param name="byref">A string-type reference address</param>
    /// <param name="format">Format YMD format</param>
    void getCurrentDateTime(std::string* byref, const std::string format);

}  // namespace util_time

#endif // !_R2R_UTIL_TIME_SYSTIME_H_