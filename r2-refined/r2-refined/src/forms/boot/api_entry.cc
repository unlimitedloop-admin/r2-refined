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
//      File name       : api_entry.cc
//
//      Author          : u7
//
//      Last update     : 2023/04/03
//
//      File version    : 2
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * Contains the entry point of the application.
**/



/* INCLUDES */
// GENERAL USING HEADER
#include <Windows.h>
// PROJECT USING HEADER
#include "kernel.h"



/* SOURCES */
/// <summary>
/// The entry point of windows application.
/// </summary>
/// <param name="hInstance">Handle to an instance</param>
/// <param name="hPrevInstance">Undefined argument, always 0</param>
/// <param name="lpszCmdLine">Unicode string command line arguments</param>
/// <param name="nCmdShow">A flag that says whether the main application window will be minimized, maximized, or shown normally</param>
/// <returns>Argument values for exit</returns>
INT APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPTSTR lpszCmdLine, _In_ int nCmdShow) {

    if (!boot::Systems(lpszCmdLine)) { return EXIT_FAILURE; }


    return EXIT_SUCCESS;

}