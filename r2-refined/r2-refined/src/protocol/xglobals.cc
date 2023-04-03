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
//      File name       : xglobals.cc
//
//      Author          : u7
//
//      Last update     : 2023/04/03
//
//      File version    : 5
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * A group of data that declares complete neutrality, the name is x-globals.
**/


/*
 * =============================================================
 *  !CAUTION!
 * =============================================================
 * When creating global scope variables, it is recommended that
 * you carefully consider whether they are needed.
 * Global variables need to be cleared.
 * That's so that you can code with confidence.
**/



/* INCLUDES */
// C++ SYSTEM HEADER
#include <string>
// GENERAL USING HEADER
#include <Windows.h>



/* SOURCES */
HWND            xg_hWnd = NULL;
HINSTANCE       xg_hInstance = NULL;
WNDPROC         xg_DxLibWnd = NULL;


std::wstring     xg_exChar = L"";
std::wstring     xg_nMsg = L"";