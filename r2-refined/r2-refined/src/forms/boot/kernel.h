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
//      File name       : kernel.h
//
//      Author          : u7
//
//      Last update     : 2023/02/08
//
//      File version    : 1
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * kernel.header
**/



#ifndef _R2R_FORMS_BOOT_KERNEL_H_
#define _R2R_FORMS_BOOT_KERNEL_H_

/* INCLUDES */
// GENERAL USING HEADER
#include <winnt.h>



/* SOURCES */
namespace boot {

    /// <summary>
    /// Run the main program.
    /// </summary>
    /// <param name="cmdline">Command line arguments</param>
    /// <returns>True or false, functions succeeded or failed</returns>
    bool Systems(LPSTR cmdline);

}  // namespace boot

#endif // !_R2R_FORMS_BOOT_KERNEL_H_