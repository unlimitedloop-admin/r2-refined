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
//      File name       : tile_loader.cc
//
//      Author          : u7
//
//      Last update     : 2023/04/03
//
//      File version    : 3
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * Implement a class that reads and uses BG tile data.
**/



/* INCLUDES */
// PRIMARY HEADER
#include "tile_loader.h"
// C++ SYSTEM HEADER
#include <string>
// GENERAL USING HEADER
#include <DxLib.h>
// PROJECT USING HEADER
#include "src/protocol/process_code_hard.h"




/* SOURCES */
namespace matter {

    namespace BG {

        TileLoader::TileLoader(const std::wstring filepath) {
            graphics_.clear();
            setFile(filepath);
        }


        TileLoader::~TileLoader() {
            for (auto& v : graphics_) {
                if (-1 == DxLib::DeleteGraph(v)) { setStaticProcessCode(0x00E6B1ULL, STATIC_ERR_DOMINATOR); }
            }
            graphics_.clear();
            graphics_.shrink_to_fit();
        }


        bool TileLoader::Unzip(const size_t all_num, const size_t x_num, const size_t y_num, const size_t x_size, const size_t y_size) {
            graphics_.resize(static_cast<size_t>(all_num));
            if (-1 == DxLib::LoadDivGraph(getFile().c_str(), all_num, x_num, y_num, x_size, y_size, &graphics_[0])) {
                setStaticProcessCode(0x00E7B1ULL, STATIC_ERR_DOMINATOR);
                return false;
            }
            return true;
        }


        bool TileLoader::Use(const __int16 axis_x, const __int16 axis_y, const size_t t_num, const bool transparent) const {
            if (t_num > graphics_.size()) { return false; }
            if (-1 == DxLib::DrawGraph(axis_x, axis_y, graphics_[t_num], transparent)) {
                setStaticProcessCode(0x00E8B1ULL, STATIC_ERR_DOMINATOR);
                return false;
            }
            return true;
        }

    }  // namespace BG

}  // namespace matter