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
//      File name       : reference.h
//
//      Author          : u7
//
//      Last update     : 2023/02/17
//
//      File version    : 1
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * reference.header
**/



#ifndef _R2R_UTIL_LOGIC_REFERENCE_H_
#define _R2R_UTIL_LOGIC_REFERENCE_H_

/* SOURCES */
namespace util_logic {

    /// <summary>
    /// Determines whether the value of an expression is within a range of interest.
    /// </summary>
    /// <typeparam name="T">Target the variable type</typeparam>
    /// <param name="expression">Target expressions</param>
    /// <param name="from">Minimum value of the range</param>
    /// <param name="to">Maximum value of the range</param>
    /// <returns>True if the expression is in range</returns>
    template <typename T>
    bool Between(T expression, T from, T to) {
        if (expression >= from && expression <= to) { return true; }
        return false;
    }

}  // namespace util_logic

#endif // !_R2R_UTIL_LOGIC_REFERENCE_H_