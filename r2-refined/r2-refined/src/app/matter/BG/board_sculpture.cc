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
//      File name       : board_sculpture.cc
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
 * Create by drawing on BG tiles.
**/



/* INCLUDES */
// PRIMARY HEADER
#include "board_sculpture.h"
// C++ SYSTEM HEADER
#include <string>
// PROJECT USING HEADER
#include "src/app/models/mat_benefits.h"
#include "tile_loader.h"



/* SOURCES */
namespace matter {

    namespace BG {

        /* using namespace */
        using namespace models;



        implements::IMatBenefits* BoardSculpture::createBoard(const std::wstring files) const {
            TileLoader* object = new TileLoader(files);
            return object;
        }

    }  // namespace BG

}  // namespace matter