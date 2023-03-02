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

    void getCurrentDateTime(std::string* byref, const std::string format) {
        std::string str = format;
        SYSTEMTIME sys;
        GetLocalTime(&sys);
        size_t sz;
        std::string tms;
        std::stringstream ss;

        // Formatting of Year.
        if (-1 != (sz = str.find("YYYY"))) {
            str.replace(sz, 4, std::to_string(sys.wYear));
        }
        else if (-1 != (sz = str.find("YY"))) {
            tms = std::to_string(sys.wYear);
            tms.erase(tms.begin(), tms.begin() + 2);
            str.replace(sz, 2, tms);
        }

        // Formatting of Month.
        if (-1 != (sz = str.find("MM"))) {
            ss << std::setfill('0') << std::setw(2) << std::to_string(sys.wMonth);
            str.replace(sz, 2, ss.str());
            ss.str("");
            ss.clear(std::stringstream::goodbit);
        }
        else if (-1 != (sz = str.find("M"))) {
            str.replace(sz, 1, std::to_string(sys.wMonth));
        }

        // Formatting of Day.
        if (-1 != (sz = str.find("DD"))) {
            ss << std::setfill('0') << std::setw(2) << std::to_string(sys.wDay);
            str.replace(sz, 2, ss.str());
            ss.str("");
            ss.clear(std::stringstream::goodbit);
        }
        else if (-1 != (sz = str.find("D"))) {
            str.replace(sz, 1, std::to_string(sys.wDay));
        }

        // Formatting of Hour.
        if (-1 != (sz = str.find("hh"))) {
            ss << std::setfill('0') << std::setw(2) << std::to_string(sys.wHour);
            str.replace(sz, 2, ss.str());
            ss.str("");
            ss.clear(std::stringstream::goodbit);
        }
        else if (-1 != (sz = str.find("h"))) {
            str.replace(sz, 1, std::to_string(sys.wHour));
        }

        // Formatting of Minute.
        if (-1 != (sz = str.find("mm"))) {
            ss << std::setfill('0') << std::setw(2) << std::to_string(sys.wMinute);
            str.replace(sz, 2, ss.str());
            ss.str("");
            ss.clear(std::stringstream::goodbit);
        }
        else if (-1 != (sz = str.find("m"))) {
            str.replace(sz, 1, std::to_string(sys.wMinute));
        }

        // Formatting of Second and Millisec.
        if (-1 != (sz = str.find("sssss"))) {
            ss << std::setfill('0') << std::setw(2) << std::to_string(sys.wSecond);
            ss << std::setfill('0') << std::setw(3) << std::to_string(sys.wMilliseconds);
            str.replace(sz, 5, ss.str());
            ss.str("");
            ss.clear(std::stringstream::goodbit);
        }
        else if (-1 != (sz = str.find("ss.sss"))) {
            ss << std::setfill('0') << std::setw(2) << std::to_string(sys.wSecond) << ".";
            ss << std::setfill('0') << std::setw(3) << std::to_string(sys.wMilliseconds);
            str.replace(sz, 6, ss.str());
            ss.str("");
            ss.clear(std::stringstream::goodbit);
        }
        else if (-1 != (sz = str.find("ss"))) {
            ss << std::setfill('0') << std::setw(2) << std::to_string(sys.wSecond);
            str.replace(sz, 2, ss.str());
            ss.str("");
            ss.clear(std::stringstream::goodbit);
        }
        else if (-1 != (sz = str.find("s"))) {
            str.replace(sz, 1, std::to_string(sys.wSecond));
        }

        *byref = str;
        //return nullptr;  // NOTE : A clamp to prevent the processing from being written here.
    }

}  // namespace util_time