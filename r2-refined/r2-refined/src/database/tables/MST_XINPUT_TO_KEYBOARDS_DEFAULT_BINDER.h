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
//      File name       : MST_XINPUT_TO_KEYBOARDS_DEFAULT_BINDER.h
//
//      Author          : u7
//
//      Last update     : 2023/04/02
//
//      File version    : 1
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * MST_XINPUT_TO_KEYBOARDS_DEFAULT_BINDER table.
**/



#ifndef _R2R_DATABASE_TABLES_MST_XINPUT_TO_KEYBOARDS_DEFAULT_BINDER_H_
#define _R2R_DATABASE_TABLES_MST_XINPUT_TO_KEYBOARDS_DEFAULT_BINDER_H_

/* INCLUDES */
// C++ SYSTEM HEADER
#include <array>
// GENERAL USING HEADER
#include <DxLib.h>
// PROJECT USING HEADER
#include "src/protocol/configuration.h"



/* SOURCES */
namespace DB {

    namespace MST_XINPUT_TO_KEYBOARDS_DEFAULT_BINDER {

        /* using namespace */
        using namespace protocol;



        /// <summary>
        /// Gets the initial array of game controllers to set on the keyboard.
        /// </summary>
        /// <param name="">Void</param>
        /// <returns>Array key number list</returns>
        std::array<uint16_t, R2R_G_JOYPADKEY> getDefaultBindKeyArray(void) {
            std::array<uint16_t, R2R_G_JOYPADKEY> key = {
                KEY_INPUT_W             // xi_up
                , KEY_INPUT_S           // xi_down
                , KEY_INPUT_A           // xi_left
                , KEY_INPUT_D           // xi_right
                , KEY_INPUT_RETURN      // xi_start_button
                , KEY_INPUT_SPACE       // xi_back_button
                , KEY_INPUT_F           // xi_ls_stick
                , KEY_INPUT_H           // xi_rs_stick
                , KEY_INPUT_1           // xi_l_button
                , KEY_INPUT_0           // xi_r_button
                , KEY_INPUT_5           // xi_lz_button
                , KEY_INPUT_7           // xi_rz_button
                , KEY_INPUT_M           // xi_a_button
                , KEY_INPUT_N           // xi_b_button
                , KEY_INPUT_L           // xi_x_button
                , KEY_INPUT_K           // xi_y_button
            };
            return key;
        }

    }  // MST_XINPUT_TO_KEYBOARDS_DEFAULT_BINDER

}  // namespace DB

#endif // !_R2R_DATABASE_TABLES_MST_XINPUT_TO_KEYBOARDS_DEFAULT_BINDER_H_