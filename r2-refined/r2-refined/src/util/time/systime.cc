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
//      File name       : systime.cc
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
 * This is system shared data management and structure kit module.
 * Includes extended operator processing that cannot be executed
 * in the standard functions of the C++ language.
**/



/* INCLUDES */
// C++ SYSTEM HEADER
#include <string>
#include <iomanip>
#include <sstream>
// GENERAL USING HEADER
#include <Windows.h>



/* SOURCES */
namespace util_time {

    void getCurrentDateTime(std::wstring* byref, const std::wstring format) {
        std::wstring str = format;
        SYSTEMTIME sys;
        GetLocalTime(&sys);
        size_t sz;
        std::wstring tms;
        std::wstringstream ss;

        // Formatting of Year.
        if (-1 != (sz = str.find(L"YYYY"))) {
            str.replace(sz, 4, std::to_wstring(sys.wYear));
        }
        else if (-1 != (sz = str.find(L"YY"))) {
            tms = std::to_wstring(sys.wYear);
            tms.erase(tms.begin(), tms.begin() + 2);
            str.replace(sz, 2, tms);
        }

        // Formatting of Month.
        if (-1 != (sz = str.find(L"MM"))) {
            ss << std::setfill(L'0') << std::setw(2) << std::to_wstring(sys.wMonth);
            str.replace(sz, 2, ss.str());
            ss.str(L"");
            ss.clear(std::wstringstream::goodbit);
        }
        else if (-1 != (sz = str.find(L"M"))) {
            str.replace(sz, 1, std::to_wstring(sys.wMonth));
        }

        // Formatting of Day.
        if (-1 != (sz = str.find(L"DD"))) {
            ss << std::setfill(L'0') << std::setw(2) << std::to_wstring(sys.wDay);
            str.replace(sz, 2, ss.str());
            ss.str(L"");
            ss.clear(std::wstringstream::goodbit);
        }
        else if (-1 != (sz = str.find(L"D"))) {
            str.replace(sz, 1, std::to_wstring(sys.wDay));
        }

        // Formatting of Hour.
        if (-1 != (sz = str.find(L"hh"))) {
            ss << std::setfill(L'0') << std::setw(2) << std::to_wstring(sys.wHour);
            str.replace(sz, 2, ss.str());
            ss.str(L"");
            ss.clear(std::wstringstream::goodbit);
        }
        else if (-1 != (sz = str.find(L"h"))) {
            str.replace(sz, 1, std::to_wstring(sys.wHour));
        }

        // Formatting of Minute.
        if (-1 != (sz = str.find(L"mm"))) {
            ss << std::setfill(L'0') << std::setw(2) << std::to_wstring(sys.wMinute);
            str.replace(sz, 2, ss.str());
            ss.str(L"");
            ss.clear(std::wstringstream::goodbit);
        }
        else if (-1 != (sz = str.find(L"m"))) {
            str.replace(sz, 1, std::to_wstring(sys.wMinute));
        }

        // Formatting of Second and Millisec.
        if (-1 != (sz = str.find(L"sssss"))) {
            ss << std::setfill(L'0') << std::setw(2) << std::to_wstring(sys.wSecond);
            ss << std::setfill(L'0') << std::setw(3) << std::to_wstring(sys.wMilliseconds);
            str.replace(sz, 5, ss.str());
            ss.str(L"");
            ss.clear(std::wstringstream::goodbit);
        }
        else if (-1 != (sz = str.find(L"ss.sss"))) {
            ss << std::setfill(L'0') << std::setw(2) << std::to_wstring(sys.wSecond) << L".";
            ss << std::setfill(L'0') << std::setw(3) << std::to_wstring(sys.wMilliseconds);
            str.replace(sz, 6, ss.str());
            ss.str(L"");
            ss.clear(std::wstringstream::goodbit);
        }
        else if (-1 != (sz = str.find(L"ss"))) {
            ss << std::setfill(L'0') << std::setw(2) << std::to_wstring(sys.wSecond);
            str.replace(sz, 2, ss.str());
            ss.str(L"");
            ss.clear(std::wstringstream::goodbit);
        }
        else if (-1 != (sz = str.find(L"s"))) {
            str.replace(sz, 1, std::to_wstring(sys.wSecond));
        }

        *byref = str;
        //return nullptr;  // NOTE : A clamp to prevent the processing from being written here.
    }

}  // namespace util_time