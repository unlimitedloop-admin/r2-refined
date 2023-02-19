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
//      File name       : keyboards_in.h
//
//      Author          : u7
//
//      Last update     : 2023/02/19
//
//      File version    : 1
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * keyboards in.header
**/



#ifndef _R2R_FORMS_DEVICE_KEYBOARDS_IN_H_
#define _R2R_FORMS_DEVICE_KEYBOARDS_IN_H_

/* SOURCES */
namespace device {

    /// <summary>
    /// Get the press status of keyboard input in an array.
    /// </summary>
    /// <param name="">Void</param>
    /// <returns>True or false, functions succeeded or failed</returns>
    bool updateAllStateKey(void);

    /// <summary>
    /// Get the pressed frame number of the specified key.
    /// </summary>
    /// <param name="number">The key ID</param>
    /// <returns>Returns the number of frames of the input key pressed, or -1 if failed</returns>
    int getHoldKeyValue(int number);

    /// <summary>
    /// Get the number of free frames for the specified key.
    /// </summary>
    /// <param name="number">The key ID</param>
    /// <returns>Returns the number of frames for keys that have not been entered, or -1 if failed</returns>
    int getFreeKeyValue(int number);

}  // namespace device

#endif // !_R2R_FORMS_DEVICE_KEYBOARDS_IN_H_