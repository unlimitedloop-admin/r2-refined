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
//      File name       : format_printer.h
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
 * format printer.header
**/



#ifndef _R2R_UTIL_FMT_FORMAT_PRINTER_H_
#define _R2R_UTIL_FMT_FORMAT_PRINTER_H_

/* INCLUDES */
// C++ SYSTEM HEADER
#include <string>
#include <cstdio>



/* SOURCES */
namespace util_fmt {

    /// <summary>
    /// <para>Creates a string using the format specification argument and returns it.</para>
    /// <para>This is an imitation of the snprintf function.</para>
    /// </summary>
    /// <typeparam name="...Args">Any datas</typeparam>
    /// <param name="fmt">Format specifier strings</param>
    /// <param name="...args">Any datas...</param>
    /// <returns>A string generated with the given number of arguments</returns>
    template <typename ... Args>
    std::wstring swprintf2(const wchar_t* fmt, Args const & ... args) {
        std::wstring str{};
        wchar_t chr_ptr[9999]{};
        if (0 <= swprintf(chr_ptr, std::size(chr_ptr), fmt, args ...)) {
            str = chr_ptr;
        }
        return str;
    }

}  // namespace util_fmt

#endif // !_R2R_UTIL_FMT_FORMAT_PRINTER_H_
