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
//      File name       : inputkey.cc
//
//      Author          : u7
//
//      Last update     : 2023/02/25
//
//      File version    : 1
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * Implements functions that control XInput input keys.
**/



/* INCLUDES */
// PRIMARY HEADER
#include "inputkey.h"
// C++ SYSTEM HEADER
#include <numeric>
// GENERAL USING HEADER
#include <DxLib.h>
// PROJECT USING HEADER
#include "key_binding.h"
#include "src/forms/device/keyboards_in.h"



/* SOURCES */
namespace input {

    bool Inputkey::updateJoyBtnStateKey(void) {
        XINPUT_STATE input;
        if (isXInputEnabled()) {
            if (-1 == GetJoypadXInputState(DX_INPUT_KEY_PAD1, &input)) { return false; }
            for (int i = 0; i < joybtn_.button_.size(); ++i) {
                if (input.Buttons[xinput_btn[i]]) {
                    ++joybtn_.button_[i];
                    joybtn_released_.button_[i] = 0;
                }
                else if (10 == i && input.LeftTrigger) {    // Left Trigger pressing state.
                    ++joybtn_.button_[i];
                    joybtn_released_.button_[i] = 0;
                }
                else if (11 == i && input.RightTrigger) {   // Right Trigger pressing state.
                    ++joybtn_.button_[i];
                    joybtn_released_.button_[i] = 0;
                }
                else {
                    joybtn_.button_[i] = 0;
                    ++joybtn_released_.button_[i];
                }
            }
        }
        else {
            for (size_t i = 0; i < joybtn_.button_.size(); ++i) {
                joybtn_.button_[i] = device::getHoldKeyValue(getBindingSCon(i));
                if (0 != joybtn_.button_[i]) {
                    joybtn_released_.button_[i] = 0;
                }
                else {
                    ++joybtn_released_.button_[i];
                }
            }
        }
        return true;
    }


    bool Inputkey::getPressingForAnyBtnKey(void) const {
        if (0 != std::accumulate(joybtn_.button_.begin(), joybtn_.button_.end(), 0)) return true;
        return false;
    }


    bool Inputkey::getReleasedForAllBtnKey(void) const {
        if (0 == std::accumulate(joybtn_.button_.begin(), joybtn_.button_.end(), 0)) return true;
        return false;
    }


    bool Inputkey::getPressingForAnyBtnKey(JPBTN* btn_args, int num) const {
        for (size_t i = 0; i < num; ++i) {
            if (joybtn_.button_[static_cast<int>(btn_args[i])]) return true;
        }
        return false;
    }


    bool Inputkey::getReleasedForAnyBtnKey(JPBTN* btn_args, int num) const {
        for (size_t i = 0; i < num; ++i) {
            if (joybtn_.button_[static_cast<int>(btn_args[i])]) return false;
        }
        return true;
    }

}  // namespace input