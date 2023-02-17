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
//      File name       : throws.h
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
 * throws.header
**/



#ifndef _R2R_EXCEPTIONS_THROWS_H_
#define _R2R_EXCEPTIONS_THROWS_H_

/* INCLUDES */
// C++ SYSTEM HEADER
#include <string>
// PROJECT USING HEADER
#include "src/traceable/logclass.h"



/* SOURCES */
namespace exceptions {

    /* using namespace */
    using namespace traceable;



    /// <summary>
    /// Abstract classes.
    /// </summary>
    class Throws {
    public:
        virtual ~Throws() {}
        virtual std::string What(unsigned __int64, LogClass) = 0;
    };

}  // namespace exceptions

#endif // !_R2R_EXCEPTIONS_THROWS_H_