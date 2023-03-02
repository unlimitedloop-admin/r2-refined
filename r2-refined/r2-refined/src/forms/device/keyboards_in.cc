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
//      File name       : keyboards_in.cc
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
 * A mechanism for acquiring keyboard input signals and controlling information.
**/



/* INCLUDES */
// C++ SYSTEM HEADER
#include <array>
// GENERAL USING HEADER
#include <DxLib.h>
// PROJECT USING HEADER
#include "src/protocol/xglobals.h"
#include "src/protocol/message_box.h"
#include "src/protocol/process_code_hard.h"
#include "src/util/fmt/format_printer.h"        /* UTILITY MODULES */



/* SOURCES */
namespace {

    const int KEY_NUM = 256;    // 256 keyboard layouts for identification used in DirectInput definitions.
    std::array<int, KEY_NUM> di_key_pressed;
    std::array<int, KEY_NUM> di_key_released;

}  // plain namespace



namespace device {

    bool updateAllStateKey(void) {
        std::array<char, KEY_NUM> key_state_array{};
        if (-1 == GetHitKeyStateAll(key_state_array.data())) {
            setStaticProcessCode(0x00E0B1ULL, STATIC_ERR_DOMINATOR);
            return false;
        }
        for (int i = 0; i < KEY_NUM; i++) {
            if (key_state_array[i] != 0) {
                if (di_key_released[i] > 0) di_key_released[i] = 0;
                di_key_pressed[i]++;
            }
            else {
                if (di_key_pressed[i] > 0) di_key_pressed[i] = 0;
                di_key_released[i]++;
            }
        }
        return true;
    }


    int getHoldKeyValue(int number) {
        if (KEY_NUM <= number) {
            xg_exChar = util_fmt::snprintf2("keyboards_in.getHoldKeyValue 検知したエラー[数値] %d", number);
            MSG_BOX(xg_exChar);
            setStaticProcessCode(0x00E1F1ULL, STATIC_ERR_DOMINATOR);
            return -1;
        }
        return di_key_pressed[number];
    }


    int getFreeKeyValue(int number) {
        if (KEY_NUM <= number) {
            xg_exChar = util_fmt::snprintf2("keyboards_in.getFreeKeyValue 検知したエラー[数値] %d", number);
            MSG_BOX(xg_exChar);
            setStaticProcessCode(0x00E1F1ULL, STATIC_ERR_DOMINATOR);
            return -1;
        }
        return di_key_released[number];
    }

}  // namespace device