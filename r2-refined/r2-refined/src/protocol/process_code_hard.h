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
//      File name       : process_code_hard.h
//
//      Author          : u7
//
//      Last update     : 2023/02/13
//
//      File version    : 1
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * process code hard.header
**/



#ifndef _R2R_PROTOCOL_PROCESS_CODE_HARD_H_
#define _R2R_PROTOCOL_PROCESS_CODE_HARD_H_

/* SOURCES */
/// A hexadecimal value that represents the processing OK. 
constexpr unsigned __int64 R2R_PROCESS_CODE_HARD_OK = 0x000000ULL;

/// Gamepad buttons.
constexpr unsigned __int16 R2R_G_JOYPADKEY = 16U;

/// <summary>
/// Get static process code for globals.
/// </summary>
/// <param name="">Void</param>
/// <returns>The value of g_static_process_code_hard</returns>
unsigned __int64 getStaticProcessCode(void);

/// <summary>
/// Set static process code for globals.
/// </summary>
/// <param name="value">Set value</param>
void setStaticProcessCode(unsigned __int64 value);

/// <summary>
/// Property to set StaticProcessCode.
/// </summary>
enum class StaticProcessSetStyle {
    CODE_RESET = 0b0000
    , PROCESS_HEAD_TWO_DIGITS = 0b0001
    , LOG_KEY_CODE_MIDDLE_DIGITS = 0b0010
    , HEAD_FOUR_DIGITS = 0b0011
    , ERROR_SEVERITY_LEVEL_DIGITS = 0b0100
    , LOG_OUTPUT_TIMES_INCREASE = 0b1000
    , CODE_ALL = 0b1111

};

// ----------------------------------------------------------------------
// The following can be implemented in a shorter form for existing enums.
#define STATIC_PROC_CD StaticProcessSetStyle::PROCESS_HEAD_TWO_DIGITS
#define STATIC_ERR_CD StaticProcessSetStyle::LOG_KEY_CODE_MIDDLE_DIGITS
#define STATIC_ERR_LVL StaticProcessSetStyle::ERROR_SEVERITY_LEVEL_DIGITS
#define STATIC_LOG_INC StaticProcessSetStyle::LOG_OUTPUT_TIMES_INCREASE

// Promise full access to the logs you specify.
#define STATIC_FULL_CD StaticProcessSetStyle::CODE_ALL

// When an error occurs.
#define STATIC_ERR_DOMINATOR STATIC_ERR_CD | STATIC_ERR_LVL | STATIC_LOG_INC


/// <summary>
/// <para>Set static process code for globals.</para>
/// <para>(An option to fill in specified digits with a hexadecimal number.)</para>
/// </summary>
/// <param name="value">Set value(Specified 0xXX or 0xXXXXXX, Any other value will not give the expected value.)</param>
/// <param name="binaries">Sets the enum value of StaticProcessSetStyle.</param>
void setStaticProcessCode(unsigned __int64 value, StaticProcessSetStyle binaries);

/// <summary>
/// OR logical gate for StaticProcessSetStyle.
/// </summary>
/// <param name="l_value">An lvalue for an OR gate</param>
/// <param name="r_value">An rvalue for an OR gate</param>
/// <returns>Returns the logical OR of the lvalue and rvalue</returns>
StaticProcessSetStyle operator|(StaticProcessSetStyle l_value, StaticProcessSetStyle r_value);

/// <summary>
/// Get static binding failure boolean for globals.
/// </summary>
/// <param name="">Void</param>
/// <returns>The boolean of g_static_binding_failure_flag</returns>
bool getStaticBindingFailureFlag(void);

/// <summary>
/// Set static binding failure boolean for globals.
/// </summary>
/// <param name="flag">Specified the Boolean of g_static_binding_failure_flag</param>
void setStaticBindingFailureFlag(bool flag);

#endif // !_R2R_PROTOCOL_PROCESS_CODE_HARD_H_