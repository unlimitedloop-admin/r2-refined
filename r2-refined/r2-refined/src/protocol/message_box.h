/**************************************************************/
//
//
//      Copyright (c) 2023 UNLIMITED LOOP ROOT-ONE
//
//
//      This software(and source code) is completely Unlicense.
//      see "LICENSE.txt".
//
//
/**************************************************************/
//
//
//      r2refined project
//
//      File name       : message_box.h
//
//      Author          : u7
//
//      Last update     : 2023/04/03
//
//      File version    : 3
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * message box.header
**/



#ifndef _R2R_PROTOCOL_MESSAGE_BOX_H_
#define _R2R_PROTOCOL_MESSAGE_BOX_H_

/* INCLUDES */
// C++ SYSTEM HEADER
#include <cstdio>
#include <string>
// GENERAL USING HEADER
#include <Windows.h>
// PROJECT USING HEADER
#include "src/protocol/env_params.h"
#include "src/protocol/xglobals.h"
#include "src/util/conv/converting.h"       /* UTILITY MODULES */



/* SOURCES */
namespace protocol {

    /// <summary>
    /// Shows a message box.
    /// </summary>
    /// <param name="message">An array of fixed strings</param>
    void showMessageBox(LPCSTR message);

    /// <summary>
    /// Shows a message box.
    /// </summary>
    /// <param name="message">An array of fixed strings</param>
    void showMessageBox(std::wstring message);


    /// <summary>
    /// Show a message box, with a printf formatting.
    /// </summary>
    /// <typeparam name="...Args">Any datas</typeparam>
    /// <param name="format">Format specifier strings</param>
    /// <param name="...args">Any datas...</param>
    template <typename ... Args>
    void showMessageBox(const wchar_t* format, Args const & ... args) {
        wchar_t cstr[1024]{};
        std::wstring str;
        if (0 <= swprintf(cstr, std::size(cstr), format, args ...)) {
            if (getParameter(L"$MESSAGE_BOX_LABELS", &str)) {
                MessageBox(xg_hWnd, WCHAR_TO_LPCWSTR(cstr), str.c_str(), MB_OK);
            }
        }
    }


    /// <summary>
    /// Show a message box, with a printf formatting.
    /// </summary>
    /// <typeparam name="...Args">Any datas</typeparam>
    /// <param name="format">Format specifier strings</param>
    /// <param name="...args">Any datas...</param>
    template <typename ... Args>
    void showMessageBox(std::wstring format, Args const & ... args) {
        wchar_t cstr[1024]{};
        std::wstring str;
        if (0 <= snprintf(cstr, std::size(cstr), format.c_str(), args ...)) {
            if (getParameter(L"$MESSAGE_BOX_LABELS", &str)) {
                MessageBox(xg_hWnd, WCHAR_TO_LPCWSTR(cstr), str.c_str(), MB_OK);
            }
        }
    }

}  // namespace protocol


// DEFINE MACROS
#define MSG_BOX(msg) protocol::showMessageBox(msg)
#define PF_MSG_BOX(msg, ...) protocol::showMessageBox(msg, __VA_ARGS__)

#endif // !_R2R_PROTOCOL_MESSAGE_BOX_H_