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
//      Last update     : 2023/04/08
//
//      File version    : 3
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
#include <tchar.h>
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
        std::wstring msg_;

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

        const wchar_t* const fname_;
        const char* const func_;
        const int line_;

    public:
        NativeMessage(const wchar_t *fname, const char *funcname, int line) : fname_(fname), func_(funcname), line_(line) {}

        /// <summary>
        /// Writes the content of the native error message to the error log.
        /// </summary>
        /// <typeparam name="...Args">Any datas</typeparam>
        /// <param name="format">Format specifier strings</param>
        /// <param name="...args">Any datas...</param>
        template<typename... Args>
        void Write(const wchar_t* format, Args&&... args) {
            size_t max_size = 8192;
            wchar_t *str_prtf = new wchar_t[max_size];
            int arg_sz = sizeof...(args);
            swprintf(str_prtf, max_size, L"FileName : %ls, FuncName : %hs, Lines : %ld, ", fname_, func_, line_);
            xg_nMsg = str_prtf;
            swprintf(str_prtf, max_size, format, args ...);
            xg_nMsg = xg_nMsg + str_prtf;
            delete[] str_prtf;
        }
    };

}  // namespace exceptions


// DEFINE MACROS
#define NATIVE_MSG(fmt, ...) exceptions::NativeMessage(_T(__FILE__), __func__, __LINE__).Write(fmt, __VA_ARGS__)

#endif // !_R2R_EXCEPTIONS_EXCEPTION_HANDLER_H_