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
//      File name       : message_box.cc
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
 * It is a function that calls the message box lightly.
**/



/* INCLUDES */
// C++ SYSTEM HEADER
#include <string>
// GENERIC USING HEADER
#include <Windows.h>
// PROJECT USING HEADER
#include "src/protocol/xglobals.h"
#include "src/protocol/env_params.h"



/* SOURCES */
namespace protocol {

    void showMessageBox(LPCSTR message) {
        std::string str;
        if (getParameter("$MESSAGE_BOX_LABELS", &str)) {
            MessageBox(xg_hWnd, message, str.c_str(), MB_OK);
        }
    }


    void showMessageBox(std::string message) {
        std::string str;
        if (getParameter("$MESSAGE_BOX_LABELS", &str)) {
            MessageBox(xg_hWnd, message.c_str(), str.c_str(), MB_OK);
        }
    }

}  // namespace protocol