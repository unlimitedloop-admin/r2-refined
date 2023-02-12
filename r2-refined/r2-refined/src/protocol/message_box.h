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
#include "src/protocol/xglobals.h"
#include "src/util/conv/converting.h"



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
    void showMessageBox(std::string message);


    /// <summary>
    /// Show a message box, with a printf formatting.
    /// </summary>
    /// <typeparam name="...Args">Any datas</typeparam>
    /// <param name="format">Format specifier strings</param>
    /// <param name="...args">Any datas...</param>
    template <typename ... Args>
    void showMessageBox(const char* format, Args const & ... args) {
        char cstr[1024]{};
        std::string str;
        if (0 <= snprintf(cstr, std::size(cstr), format, args ...)) {
            if (getParameter("$MESSAGE_BOX_LABELS", &str)) {
                MessageBox(xg_hWnd, CHAR_TO_LPCSTR(cstr), str.c_str(), MB_OK);
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
    void showMessageBox(std::string format, Args const & ... args) {
        char cstr[1024]{};
        std::string str;
        if (0 <= snprintf(cstr, std::size(cstr), format.c_str(), args ...)) {
            if (getParameter("$MESSAGE_BOX_LABELS", &str)) {
                MessageBox(xg_hWnd, CHAR_TO_LPCSTR(cstr), str.c_str(), MB_OK);
            }
        }
    }

}  // namespace protocol


// DEFINE MACROS
#define MSG_BOX(msg) protocol::showMessageBox(msg)
#define PF_MSG_BOX(msg, ...) protocol::showMessageBox(msg, __VA_ARGS__)

#endif // !_R2R_PROTOCOL_MESSAGE_BOX_H_