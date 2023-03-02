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
//      File name       : key_binding.h
//
//      Author          : u7
//
//      Last update     : 2023/03/01
//
//      File version    : 2
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * key binding.header
**/



#ifndef _R2R_APP_INPUT_KEY_BINDING_H_
#define _R2R_APP_INPUT_KEY_BINDING_H_

/* SOURCES */
namespace input {

    /// <summary>
    /// Set XInputModulation.
    /// </summary>
    /// <param name="keys">The keys to fill in the sCon array in order</param>
    /// <param name="hatsw">Hat switch enabled/disabled</param>
    /// <param name="joypad">Gamepad enable/disable</param>
    /// <returns>True or false, functions succeeded or failed</returns>
    bool setBindingSCon(unsigned __int16 keys[], bool hatsw, bool joypad);

    /// <summary>
    /// Get key configs of XInputModulation.
    /// </summary>
    /// <param name="num">Keyboard array number</param>
    /// <returns>Key array value</returns>
    unsigned __int16 getBindingSCon(unsigned __int16 num);

    /// <summary>
    /// Check if XInput is enabled.
    /// </summary>
    /// <param name="">Void</param>
    /// <returns>True enables XInput, false disables</returns>
    bool isXInputEnabled(void);

    /// <summary>
    /// Set Scon's default key.
    /// </summary>
    /// <param name="">Void</param>
    /// <returns>True or false, functions succeeded or failed</returns>
    bool defaultSetBindingSCon(void);

}  // namespace input

#endif // !_R2R_APP_INPUT_KEY_BINDING_H_