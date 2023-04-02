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
//      File name       : inputkey.h
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
 * inputkey.header
**/



#ifndef _R2R_APP_INPUT_INPUTKEY_H_
#define _R2R_APP_INPUT_INPUTKEY_H_

/* INCLUDES */
// C++ SYSTEM HEADER
#include <array>
// GENERAL USING HEADER
#include <DxLib.h>
// PROJECT USING HEADER
#include "src/protocol/configuration.h"
#include "src/protocol/process_code_hard.h"
#include "src/app/models/signature_object.h"



/* SOURCES */
namespace {

    /* using namespace */
    using namespace protocol;



    typedef struct tC16Button {
        std::array<__int32, R2R_G_JOYPADKEY> button_;
    } *LPtC16Button;

}  // plain namespace



namespace input {

    /// <summary>
    /// Keylist for gamepads.
    /// </summary>
    enum class JPBTN {
        UP
        , DOWN
        , LEFT
        , RIGHT
        , START
        , BACK
        , LSTICK
        , RSTICK
        , L
        , R
        , LZT
        , RZT
        , A
        , B
        , X
        , Y
    };


    /// <summary>
    /// Input key implementation class. (friend to Singleton abstract classes.)
    /// </summary>
    class Inputkey final : public models::Singleton<Inputkey> {
        friend models::Singleton<Inputkey>;

    private:
        tC16Button joybtn_{};           // Joycard press button array.
        tC16Button joybtn_released_{};  // Joycard release button array.
        
        /// <summary>
        /// For XInput only.
        /// </summary>
        const size_t xinput_btn[R2R_G_JOYPADKEY] = {
            XINPUT_BUTTON_DPAD_UP
            , XINPUT_BUTTON_DPAD_DOWN
            , XINPUT_BUTTON_DPAD_LEFT
            , XINPUT_BUTTON_DPAD_RIGHT
            , XINPUT_BUTTON_START
            , XINPUT_BUTTON_BACK
            , XINPUT_BUTTON_LEFT_THUMB
            , XINPUT_BUTTON_RIGHT_THUMB
            , XINPUT_BUTTON_LEFT_SHOULDER
            , XINPUT_BUTTON_RIGHT_SHOULDER
            , 10
            , 11
            , XINPUT_BUTTON_A
            , XINPUT_BUTTON_B
            , XINPUT_BUTTON_X
            , XINPUT_BUTTON_Y
        };

    public:
        Inputkey() {}
        Inputkey(const Inputkey&) = delete;
        ~Inputkey() = default;

        /// <summary>
        /// Get keyboard input information and apply it to gamepad press information.
        /// </summary>
        /// <param name="">Void</param>
        /// <returns>True or false, functions succeeded or failed</returns>
        bool updateJoyBtnStateKey(void);

        /// <summary>
        /// Get the information that the gamepad key is pressed.
        /// </summary>
        /// <param name="btn_num">The button name definition</param>
        /// <returns>Press time of the specified key (number of frames).</returns>
        __int32 getPressJoyBtnKey(JPBTN btn_num) const {
            return joybtn_.button_[static_cast<int>(btn_num)];
        }

        /// <summary>
        /// Get the information that the gamepad key is released.
        /// </summary>
        /// <param name="btn_num">The button name difinition</param>
        /// <returns>The amount of time the specified key has not been pressed (number of frames).</returns>
        __int32 getReleaseJoyBtnKey(JPBTN btn_num) const {
            return joybtn_released_.button_[static_cast<int>(btn_num)];
        }

        /// <summary>
        /// Checks if any key on the gamepad is pressed.
        /// </summary>
        /// <param name="">Void</param>
        /// <returns>True if any key is pressed</returns>
        bool getPressingForAnyBtnKey(void) const;

        /// <summary>
        /// Checks that keys are no pressed.
        /// </summary>
        /// <param name="">Void</param>
        /// <returns>True if all key is not pressed</returns>
        bool getReleasedForAllBtnKey(void) const;

        /// <summary>
        /// Checks if any of the specified keys is pressed.
        /// </summary>
        /// <param name="btn_args">Multiple key identifiers</param>
        /// <param name="num">The number of specified keys</param>
        /// <returns>True if any key is pressed for any specified keys</returns>
        bool getPressingForAnyBtnKey(JPBTN* btn_args, int num) const;

        /// <summary>
        /// Checks that all specified keys are not pressed.
        /// </summary>
        /// <param name="btn_args">Multiple key identifiers</param>
        /// <param name="num">The number of specified keys</param>
        /// <returns>True if all specified keys are not pressed</returns>
        bool getReleasedForAnyBtnKey(JPBTN* btn_args, int num) const;
    };


    //#define GController Inputkey::getInstance()
    extern Inputkey* GController();

    //#define GetKey Inputkey::getInstance()->getPressJoyBtnKey
    extern __int32 GetKey(JPBTN x);

    //#define GetKey Inputkey::getInstance()->getReleaseJoyBtnKey
    extern __int32 GetFreeKey(JPBTN x);

}  // namespace input

#endif // !_R2R_APP_INPUT_INPUTKEY_H_