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
//      File name       : process_code_hard.cc
//
//      Author          : u7
//
//      Last update     : 2023/02/17
//
//      File version    : 2
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * Implement getters and setters with global scope processing tracking code.
**/



/* INCLUDES */
// PRIMARY HEADER
#include "process_code_hard.h"



/* SOURCES */
static bool g_static_binding_failure_flag = false;
static unsigned __int64 g_static_process_code_hard = R2R_PROCESS_CODE_HARD_OK;



unsigned __int64 getStaticProcessCode(void) {
    return g_static_process_code_hard;
}


void setStaticProcessCode(unsigned __int64 value) {
    g_static_process_code_hard = value;
}


void setStaticProcessCode(unsigned __int64 value, StaticProcessSetStyle binaries) {
    // Reset the Static processing code. 
    if (StaticProcessSetStyle::CODE_RESET == binaries) { g_static_process_code_hard = 0x000000ULL; }
    auto convInt = [](StaticProcessSetStyle const& value) { return static_cast<int>(value); };
    // Check the value of 1st bit of the binary number that the argument and change the static processing code of the upper two digits.
    if ((convInt(binaries) & convInt(StaticProcessSetStyle::PROCESS_HEAD_TWO_DIGITS)) == convInt(StaticProcessSetStyle::PROCESS_HEAD_TWO_DIGITS)) {
        if (0x100 > value) { g_static_process_code_hard = (value * 0x010000ULL) + (g_static_process_code_hard % 0x010000ULL); }
        else { g_static_process_code_hard = (value / 0x010000ULL * 0x010000ULL) + (g_static_process_code_hard % 0x010000ULL); }
    }
    // Check the value of 2nd bit of the binary number that the argument and change the error code of the static processing code. 
    if ((convInt(binaries) & convInt(StaticProcessSetStyle::LOG_KEY_CODE_MIDDLE_DIGITS)) == convInt(StaticProcessSetStyle::LOG_KEY_CODE_MIDDLE_DIGITS)) {
        if (0x100 > value) { g_static_process_code_hard = (g_static_process_code_hard / 0x010000ULL * 0x010000ULL) + (value * 0x0100ULL) + (g_static_process_code_hard % 0x000100ULL); }
        else { g_static_process_code_hard = (g_static_process_code_hard / 0x010000ULL * 0x010000ULL) + (value & 0x00FF00LL) + (g_static_process_code_hard % 0x000100ULL); }
    }
    // Check the value of 3rd bit of the binary number, replace the error frequency with the obtained value.
    if ((convInt(binaries) & convInt(StaticProcessSetStyle::ERROR_SEVERITY_LEVEL_DIGITS)) == convInt(StaticProcessSetStyle::ERROR_SEVERITY_LEVEL_DIGITS)) {
        if (0x10 > value) { g_static_process_code_hard = (g_static_process_code_hard / 0x000100ULL * 0x000100ULL) + (value * 0x000010ULL) + (g_static_process_code_hard % 0x000010ULL); }
        else { g_static_process_code_hard = (g_static_process_code_hard / 0x000100ULL * 0x000100ULL) + (value & 0x0000F0LL) + (g_static_process_code_hard % 0x000010ULL); }
    }
    // Increments the error count counter when the value of the 4th bit of the binary number is 1.
    if ((convInt(binaries) & convInt(StaticProcessSetStyle::LOG_OUTPUT_TIMES_INCREASE)) == convInt(StaticProcessSetStyle::LOG_OUTPUT_TIMES_INCREASE)) {
        if (0xF != (g_static_process_code_hard & 0x00000FULL)) { g_static_process_code_hard++; }
    }
}


StaticProcessSetStyle operator|(StaticProcessSetStyle l_value, StaticProcessSetStyle r_value) {
    return static_cast<StaticProcessSetStyle>(static_cast<int>(l_value) | static_cast<int>(r_value));
}


bool getStaticBindingFailureFlag(void) {
    return g_static_binding_failure_flag;
}


void setStaticBindingFailureFlag(bool flag) {
    g_static_binding_failure_flag = flag;
}