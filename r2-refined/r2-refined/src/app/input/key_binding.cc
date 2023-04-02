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
//      File name       : key_binding.cc
//
//      Author          : u7
//
//      Last update     : 2023/04/02
//
//      File version    : 3
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * Implement the key configuration function of the game controller.
**/



/* INCLUDES */
// C++ SYSTEM HEADER
#include <array>
// GENERAL USING HEADER
#include <DxLib.h>
// PROJECT USING HEADER
#include "inputkey.h"
#include "src/protocol/configuration.h"
#include "src/database/tables/MST_XINPUT_TO_KEYBOARDS_DEFAULT_BINDER.h"



/* SOURCES */
namespace {

    /* using namespace */
    using namespace protocol;




    /// <summary>
    /// A key list containing Z-trigger values, ThumbL and ThumbR as buttons.
    /// </summary>
    typedef struct {
        unsigned __int16 xi_up;             // [0]
        unsigned __int16 xi_down;           // [1]
        unsigned __int16 xi_left;           // [2]
        unsigned __int16 xi_right;          // [3]
        unsigned __int16 xi_start_button;   // [4]
        unsigned __int16 xi_back_button;    // [5]
        unsigned __int16 xi_ls_stick;       // [6]
        unsigned __int16 xi_rs_stick;       // [7]
        unsigned __int16 xi_l_button;       // [8]
        unsigned __int16 xi_r_button;       // [9]
        unsigned __int16 xi_lz_button;      // [10]
        unsigned __int16 xi_rz_button;      // [11]
        unsigned __int16 xi_a_button;       // [12]
        unsigned __int16 xi_b_button;       // [13]
        unsigned __int16 xi_x_button;       // [14]
        unsigned __int16 xi_y_button;       // [15]
        bool hatswitch_enabled;             // The hat switch is a cross button.
        bool xinput_enabled;                // Enable XInput controller.
    } XInputModulation;

    XInputModulation s_con;     // A connected XInput gamepad.

}  // plain namespace



namespace input {

    bool setBindingSCon(const std::array<uint16_t, R2R_G_JOYPADKEY> keys, const bool hatsw, const bool joypad) {
        s_con.xinput_enabled = joypad;
        if (!s_con.xinput_enabled) {
            // xi_up to xi_y_button assignment.
            unsigned __int16* ptr = &s_con.xi_up;
            for (size_t i = 0; i < R2R_G_JOYPADKEY; ++i) {
                if (0xFF < keys[i]) { return false; }
                *ptr = keys[i];
                ++ptr;
            }
        }
        s_con.hatswitch_enabled = hatsw;
        return true;
    }


    unsigned __int16 getBindingSCon(const unsigned __int16 num) {
        unsigned __int16* ptr = &s_con.xi_up;
        return *(ptr + num);
    }


    bool isXInputEnabled(void) {
        return s_con.xinput_enabled;
    }


    bool defaultSetBindingSCon(void) {
        // Only do keyboard key bindings when no gamepad is connected.
        if (GetJoypadNum()) {
            if (!setBindingSCon({}, true, true)) {
                setStaticProcessCode(0x001DC1ULL, STATIC_FULL_CD);
                return false;
            }
        }
        else {
            if (!setBindingSCon(DB::MST_XINPUT_TO_KEYBOARDS_DEFAULT_BINDER::getDefaultBindKeyArray(), true, false)) {
                setStaticProcessCode(0x001DC1ULL, STATIC_FULL_CD);
                return false;
            }
        }
        return true;
    }

}  // namespace input