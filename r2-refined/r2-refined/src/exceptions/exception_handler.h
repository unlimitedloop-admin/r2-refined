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
//      File name       : exception_handler.h
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
 * exception handler.header
**/



#ifndef _R2R_EXCEPTIONS_EXCEPTION_HANDLER_H_
#define _R2R_EXCEPTIONS_EXCEPTION_HANDLER_H_

/* INCLUDES */
// C++ SYSTEM HEADER
#include <cstdio>
#include <cstdlib>
#include <string>
// GENERAL USING HEADER
#include <Windows.h>
// PROJECT USING HEADER
#include "throws.h"
#include "src/protocol/xglobals.h"



/* SOURCES */
namespace exceptions {

    /// <summary>
    /// A class containing functions for handling exceptions.
    /// </summary>
    class ExceptionHandler final {
    private:
        Throws* creature_;
        std::string msg_;

    public:
        ExceptionHandler();
        ~ExceptionHandler();

        /// <summary>
        /// A fixed action that should be performed when an error occurs.
        /// </summary>
        /// <param name="bool">Set to true when forced termination</param>
        void throwException(bool);
    };


    /// <summary>
    /// A logger class for spitting out native source debug information.
    /// </summary>
    class NativeMessage {
    private:
        NativeMessage() = delete;
        NativeMessage(const NativeMessage&) = delete;

        const char* const fname_;
        const char* const func_;
        const int line_;

    public:
        NativeMessage(const char *fname, const char *funcname, int line) : fname_(fname), func_(funcname), line_(line) {}

        /// <summary>
        /// Writes the content of the native error message to the error log.
        /// </summary>
        /// <typeparam name="...Args">Any datas</typeparam>
        /// <param name="format">Format specifier strings</param>
        /// <param name="...args">Any datas...</param>
        template<typename... Args>
        void Write(const char* format, Args&&... args) {
            char str_prtf[9999]{};
            int arg_sz = sizeof...(args);
            snprintf(str_prtf, std::size(str_prtf), "FileName : %s, FuncName : %s, Lines : %d, ", fname_, func_, line_);
            xg_nMsg = str_prtf;
            snprintf(str_prtf, std::size(str_prtf), format, args ...);
            xg_nMsg = xg_nMsg + str_prtf;
        }
    };

}  // namespace exceptions


// DEFINE MACROS
#define NATIVE_MSG(fmt, ...) exceptions::NativeMessage(__FILE__, __func__, __LINE__).Write(fmt, __VA_ARGS__)

#endif // !_R2R_EXCEPTIONS_EXCEPTION_HANDLER_H_