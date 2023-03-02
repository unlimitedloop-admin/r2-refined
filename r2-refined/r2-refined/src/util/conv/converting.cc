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
 * This is system shared data management and structure kit module.
 * Includes extended operator processing that cannot be executed
 * in the standard functions of the C++ language.
**/



/* INCLUDES */
// C++ SYSTEM HEADER
#include <string>
#include <stdexcept>



/* SOURCES */
namespace util_conv {

    const char* charToConstChar(char* expression) {
        return const_cast<char*>(expression);
    }


    bool tryParseStrToInt(int* byref, std::string num_str) {
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


    bool tryParseStrToDouble(double* byref, std::string num_str) {
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
