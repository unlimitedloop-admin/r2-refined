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
//      File name       : xglobals.h
//
//      Author          : u7
//
//      Last update     : 2023/04/03
//
//      File version    : 6
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * xglobals.header
**/



#ifndef _R2R_PROTOCOL_XGLOBALS_H_
#define _R2R_PROTOCOL_XGLOBALS_H_

/* INCLUDES */
// C++ SYSTEM HEADER
#include <string>
// GENERAL USING HEADER
#include <Windows.h>



/* SOURCES */
/// <summary>
/// <para>A window handle that can be used equally throughout the system.</para>
/// <para>The screen displayed in the main is set to this.</para>
/// </summary>
extern HWND xg_hWnd;

/// <summary>
/// Main instance of the system. The instance is WINAPI-specific.
/// </summary>
extern HINSTANCE xg_hInstance;

/// <summary>
/// Holds window handlers for windows created with DxLib.
/// </summary>
extern WNDPROC xg_DxLibWnd;

/// <summary>
/// Global exception message storages.
/// </summary>
extern std::wstring xg_exChar;

/// <summary>
/// Native error descriptions. (Supplemental Information)
/// </summary>
extern std::wstring xg_nMsg;


#endif // !_R2R_PROTOCOL_XGLOBALS_H_