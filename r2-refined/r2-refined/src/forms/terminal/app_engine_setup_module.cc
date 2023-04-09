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
//      File name       : app_engine_setup_module.cc
//
//      Author          : u7
//
//      Last update     : 2023/04/09
//
//      File version    : 2
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * The main game engine at the core of this application. (Partial divided)
**/



/* INCLUDES */
// PRIMARY HEADER
#include "app_engine.h"
// C++ SYSTEM HEADER
#include <string>
#include <functional>
// GENERAL USING HEADER
#include <Windows.h>
#include <DxLib.h>
// PROJECT USING HEADER
#include "resource.h"
#include "src/protocol/evaluation.h"
#include "src/protocol/env_params.h"
#include "src/traceable/output_logs.h"
#include "src/util/conv/converting.h"           /* UTILITY MODULES */



/* SOURCES */
namespace terminal {

    /* using namespace */
    using namespace protocol;
    using namespace traceable;



    bool AppEngine::runmodeChoice(const RunMode expr, ResultSet& outparameter1, ResultSet& outparameter2, std::function<bool(uint64_t)> func) {
        std::wstring str = L"";
        if (getParameter(L"$HIDDEN_DRIVER", &str)) {
            if (L"1" == str) {
                outparameter1 = ResultSet::ENABLED;
                (void)writeStatusLog(L"テストモジュールを起動します。", LogClass::LOG_LEVEL_OFF);
            }
        }
        // Check for development mode flag. (For development, normally 0)
        else if (getParameter(L"$DEV_MODE", &str)) {
            if (L"1" == str) {
                outparameter2 = ResultSet::ENABLED;
                (void)writeStatusLog(L"システムはデヴェロップメントモードで開始されます。", LogClass::LOG_LEVEL_OFF);
            }
        }
        // Output DxLib log. Specify the output destination of the DxLib exclusive log before calling the DxLib function. 
        if (RunMode::GENERAL_MODE == expr) {
            if (0 != DxLib::SetOutApplicationLogValidFlag(FALSE)) { return func(0x000771ULL); }
        }
        else {
            if (getParameter(L"$DXLIB_OUTPUT_LOG_PATH", &str)) {
                if (0 != DxLib::SetApplicationLogSaveDirectory(str.c_str())) { return func(0x000871ULL); }
            }
            else {
                if (0 != DxLib::SetOutApplicationLogValidFlag(FALSE)) { return func(0x000771ULL); }
            }
        }
        return true;
    }


    bool AppEngine::runInBackground(std::function<bool(uint64_t)> func) const {
        std::wstring str = L"";
        // Active (or inactive) window always running application.
        if (getParameter(L"$WINDOW_ALWAYS_RUN_ENABLED", &str)) {
            if (L"1" == str) {
                if (0 != DxLib::SetAlwaysRunFlag(TRUE)) { return func(0x000951ULL); }
            }
            else {
                if (0 != DxLib::SetAlwaysRunFlag(FALSE)) { return func(0x000A51ULL); }
            }
        }
        return true;
    }


    bool AppEngine::setWindowConfigs(std::function<bool(uint64_t)> func) {
        std::wstring str = L"";
        // Screen setup.
        if ((void)getParameter(L"$WINDOW_MODE_ENABLED", &str); L"0" == str) {
            if (DX_CHANGESCREEN_OK != DxLib::ChangeWindowMode(FALSE)) { return func(0x000BF1ULL); }
            if (0 != DxLib::SetUseMenuFlag(FALSE)) { return func(0x000C91ULL); }
        }
        else {
            // Default route.
            if (DX_CHANGESCREEN_OK != DxLib::ChangeWindowMode(TRUE)) { return func(0x000DF1ULL); }
            if (0 != DxLib::SetWindowPosition(10, 10)) { return func(0x000E71ULL); }
            str.clear();
            if (getParameter(L"$WINDOW_EXTEND_RATE", &str)) {
                double rate;
                if (!str.empty() && util_conv::tryParseStrToDouble(&rate, str)) {
                    if (0 != DxLib::SetWindowSizeExtendRate(rate)) { return func(0x000F70ULL); }
                }
            }
            auto size = 0, winsizex = 0, winsizey = 0, colorbit = 0;
            str.clear();
            (void)getParameter(L"$WINDOW_HORIZONAL_SIZE", &str);
            if (!str.empty() && util_conv::tryParseStrToInt(&size, str)) winsizex = size;
            str.clear();
            (void)getParameter(L"$WINDOW_VERTICAL_SIZE", &str);
            if (!str.empty() && util_conv::tryParseStrToInt(&size, str)) winsizey = size;
            str.clear();
            (void)getParameter(L"$WINDOW_COLOR_BITS", &str);
            if (!str.empty() && util_conv::tryParseStrToInt(&size, str)) colorbit = size;
            if (winsizex && winsizey && colorbit) {
                if (DX_CHANGESCREEN_OK != DxLib::SetGraphMode(winsizex, winsizey, colorbit)) {
                    if (DX_CHANGESCREEN_OK != DxLib::SetGraphMode(256, 240, 16)) { return func(0x0012F1ULL); }
                }
            }
            else {
                if (DX_CHANGESCREEN_OK != DxLib::SetGraphMode(256, 240, 16)) { return func(0x0012F1ULL); }
                if (0 != DxLib::SetWindowSizeExtendRate(1.0)) { return func(0x000F70ULL); }
            }
            // NOTE : Edit resource files only in Visual Studio.
            if (0 != DxLib::LoadMenuResource(IDR_MENU1)) { return func(0x001AB1ULL); }
            if (0 != DxLib::SetUseMenuFlag(TRUE)) { return func(0x001B90ULL); }
        }
        // Specified application title.
        str.clear();
        if (getParameter(L"$WINDOW_TEXT", &str)) {
            if (!str.empty()) {
                if (0 != DxLib::SetWindowText(str.c_str())) { return func(0x0013A0ULL); }
            }
        }
        return true;
    }

}  // namespace terminal