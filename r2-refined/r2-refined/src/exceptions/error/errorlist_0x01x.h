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
//      File name       : errorlist_0x01x.h
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
 * errorlist 0x01x.header
**/



#ifndef _R2R_EXCEPTIONS_ERROR_ERRORLIST_0X01X_H_
#define _R2R_EXCEPTIONS_ERROR_ERRORLIST_0X01X_H_

/* INCLUDES */
// PRIMARY HEADER
#include "errorlist_overlapped.h"
// C++ SYSTEM HEADER
#include <string>
// PROJECT USING HEADER
#include "src/traceable/logclass.h"



/* SOURCES */
namespace exceptions {

    /* using namespace */
    using namespace traceable;



    /// <summary>
    /// Error list corresponding to error code 0x0100 to 0x01FF.
    /// </summary>
    class ErrorList0x01x final : public ErrorListOverlapped {
    public:
        ErrorList0x01x() {}
        ~ErrorList0x01x() {}

        /// <summary>
        /// Outputs an error message to the log based on the error code.
        /// </summary>
        /// <param name="unsigned __int64">Error codes</param>
        /// <param name="LogClass">Log levels</param>
        /// <returns>Concrete error statements</returns>
        std::string Minor(unsigned __int64, LogClass) override;
    };

}  // namespace exceptions

#endif // !_R2R_EXCEPTIONS_ERROR_ERRORLIST_0X01X_H_