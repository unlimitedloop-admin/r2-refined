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
//      File name       : errorlist_overlapped.h
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
 * errorlist overlapped.header
**/



#ifndef _R2R_EXCEPTIONS_ERROR_ERRORLIST_OVERLAPPED_H_
#define _R2R_EXCEPTIONS_ERROR_ERRORLIST_OVERLAPPED_H_

/* INCLUDES */
// PRIMARY HEADER
#include "../throws.h"
// C++ SYSTEM HEADER
#include <string>
// PROJECT USING HEADER
#include "src/traceable/logclass.h"



/* SOURCES */
namespace exceptions {

    /* using namespace */
    using namespace traceable;



    /// <summary>
    /// Error list corresponding to error code common number.
    /// </summary>
    class ErrorListOverlapped : public Throws {
    public:
        ErrorListOverlapped() {}
        ~ErrorListOverlapped() {}

        /// <summary>
        /// Outputs an error message to the log based on the error code.
        /// </summary>
        /// <param name="unsigned __int64">Error codes</param>
        /// <param name="LogClass">Log levels</param>
        /// <returns>Concrete error statements</returns>
        std::string Major(unsigned __int64, LogClass) override;
    };

}  // namespace exceptions

#endif // !_R2R_EXCEPTIONS_ERROR_ERRORLIST_OVERLAPPED_H_