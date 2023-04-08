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
//      File name       : tile_arrays.cc
//
//      Author          : u7
//
//      Last update     : 2023/04/08
//
//      File version    : 4
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * Implement the process of spreading and arranging BG tiles.
**/



/* INCLUDES */
// PRIMARY HEADER
#include "tile_arrays.h"
// C++ SYSTEM HEADER
#include <string>
// PROJECT USING HEADER
#include "src/app/matter/BG/sculpture.h"
#include "src/app/matter/BG/board_sculpture.h"
#include "src/app/matter/structures/tag_divgraph_p.h"
#include "src/protocol/process_code_hard.h"
#include "src/protocol/xglobals.h"
#include "src/util/conv/converting.h"           /* UTILITY MODULES */



/* SOURCES */
namespace matter {

    namespace BG {

        TileArrays::TileArrays() {
            texture_ = nullptr;
        }


        TileArrays::TileArrays(const TileArrays& cc) {
            texture_ = cc.texture_;
        }


        TileArrays::~TileArrays() {
            if (nullptr != texture_) {
                delete texture_;
                texture_ = nullptr;
            }
        }


        bool TileArrays::loadStructure(const std::wstring bin_filepath, const size_t pages) {
            if (!structure_.Loading(bin_filepath, pages)) {
                return false;
            }
            return true;
        }

        
        bool TileArrays::loadTexture(const std::wstring filepath, const LPDivGraphParam params) {
            extends::Sculpture* factory = new BoardSculpture();
            texture_ = factory->Create(filepath);
            if (!texture_->Unzip(params->all_num, params->x_num, params->y_num, params->x_size, params->y_size)) { return false; }
            delete factory;
            return true;
        }


        bool TileArrays::mappingOn(const size_t map_no, const __int16 axis_x, const __int16 axis_y) const {
            try {
                size_t index = 0;
                for (size_t i = 0; i < 15; ++i) {
                    for (size_t j = 0; j < 16; ++j) {
                        index = structure_.getMapData(map_no, i, j);
                        texture_->Use((j * 16), (i * 16), index, false);
                    }
                }
            }
            catch (std::exception& e) {
                xg_exChar = CHAR_TO_WSTRING(e.what());
                setStaticProcessCode(0x0000F1ULL, STATIC_ERR_DOMINATOR);
                return false;
            }

            return true;
        }

    }  // namespace BG

}  // namespace matter