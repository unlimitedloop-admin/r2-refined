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
//      File name       : hardware_check.h
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
 * hardware check.header
**/



#ifndef _R2R_FORMS_BOOT_HARDWARE_CHECK_H_
#define _R2R_FORMS_BOOT_HARDWARE_CHECK_H_

/* SOURCES */
namespace boot {

    /// <summary>
    /// Check the execution environment.
    /// </summary>
    /// <param name="">Void</param>
    /// <returns>True if the environment has been proven to executive properly</returns>
    bool checkingSystemInfo(void);

}  // namespace boot

#endif // !_R2R_FORMS_BOOT_HARDWARE_CHECK_H_