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
//      File name       : sprite_loader.h
//
//      Author          : u7
//
//      Last update     : 2023/03/11
//
//      File version    : 1
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * Implement a class that reads and uses sprite data.
**/



/* INCLUDES */
// PRIMARY HEADER
#include "sprite_loader.h"
// C++ SYSTEM HEADER
#include <string>
// GENERAL USING HEADER
#include <DxLib.h>
// PROJECT USING HEADER
#include "src/protocol/process_code_hard.h"




/* SOURCES */
namespace matter {

    namespace sprite {

        SpriteLoader::SpriteLoader(std::string filepath) {
            graphics_.clear();
            setFile(filepath);
        }


        SpriteLoader::~SpriteLoader() {
            for (auto& v : graphics_) {
                if (-1 == DxLib::DeleteGraph(v)) { setStaticProcessCode(0x00E2B1ULL, STATIC_ERR_DOMINATOR); }
            }
            graphics_.clear();
            graphics_.shrink_to_fit();
        }


        bool SpriteLoader::Unzip(size_t all_num, size_t x_num, size_t y_num, size_t x_size, size_t y_size) {
            graphics_.resize(static_cast<size_t>(all_num));
            if (-1 == DxLib::LoadDivGraph(getFile().c_str(), all_num, x_num, y_num, x_size, y_size, &graphics_[0])) {
                setStaticProcessCode(0x00E3B1ULL, STATIC_ERR_DOMINATOR);
                return false;
            }
            return true;
        }


        bool SpriteLoader::Use(__int16 axis_x, __int16 axis_y, size_t t_num, bool transparent) const {
            if (t_num > graphics_.size()) { return false; }
            if (-1 == DxLib::DrawGraph(axis_x, axis_y, graphics_[t_num], transparent)) {
                setStaticProcessCode(0x00E4B1ULL, STATIC_ERR_DOMINATOR);
                return false;
            }
            return true;
        }

    }  // namespace sprite

}  // namespace matter