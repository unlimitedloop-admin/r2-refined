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
//      File name       : errorlist_0x01x.cc
//
//      Author          : u7
//
//      Last update     : 2023/02/19
//
//      File version    : 1
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * Error list corresponding to error code 0x0100 to 0x01FF.
**/



/* INCLUDES */
// PRIMARY HEADER
#include "errorlist_0x01x.h"
// C++ SYSTEM HEADER
#include <string>
#include <sstream>
// PROJECT USING HEADER
#include "src/traceable/logclass.h"



/* SOURCES */
namespace exceptions {

    /* using namespace */
    using namespace traceable;



    std::string ErrorList0x01x::Minor(unsigned __int64 error_code, LogClass level) {
        std::ostringstream message;
        const std::string str_crlf = "\r\n";

        switch (error_code / 0x000100ULL) {
        case 0x0101ULL:
            message << "processcode 0x010000のエラー。";
            break;
        default:
            message << "未定義エラー。";
            break;
        }

        return message.str();
    }

}  // namespace exceptions