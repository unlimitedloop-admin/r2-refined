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
//      File name       : converting.cc
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
 * This is system shared data management and structure kit module.
 * Includes extended operator processing that cannot be executed
 * in the standard functions of the C++ language.
**/



/* INCLUDES */
// C++ SYSTEM HEADER
#include <string>
#include <stdexcept>
// GENERAL USING HEADER
#include <Windows.h>



/* SOURCES */
namespace util_conv {

    const wchar_t* wcharToConstWchar(wchar_t* expression) {
        return const_cast<wchar_t*>(expression);
    }


    std::wstring charToWstring(const char* expression) {
        size_t len = MultiByteToWideChar(CP_UTF8, 0, expression, -1, nullptr, 0);
        std::wstring wstr(len, L'\0');
        MultiByteToWideChar(CP_UTF8, 0, expression, -1, &wstr[0], len);
        return wstr;
    }


    bool tryParseStrToInt(int* byref, std::wstring num_str) {
        try {
            int num;
            num = std::stoi(num_str, nullptr);
            *byref = num;
            return true;
        }
        catch (std::logic_error& e) {
            return false;
        }
    }


    bool tryParseStrToDouble(double* byref, std::wstring num_str) {
        try {
            double d_num;
            d_num = std::stod(num_str, nullptr);
            *byref = d_num;
            return true;
        }
        catch (std::logic_error& e) {
            return false;
        }
    }

}  // namespace util_conv
