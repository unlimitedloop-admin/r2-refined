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
 * This is system shared data management and structure kit module.
 * Includes extended operator processing that cannot be executed
 * in the standard functions of the C++ language.
**/



/* INCLUDES */
// C++ SYSTEM HEADER
#include <Windows.h>



/* SOURCES */
namespace util_conv {

    const char* charToConstChar(char* expression) {
        return const_cast<char*>(expression);
    }

}  // namespace util_conv
