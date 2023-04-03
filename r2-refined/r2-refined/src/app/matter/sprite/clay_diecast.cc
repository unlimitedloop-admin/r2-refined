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
//      File name       : clay_diecast.cc
//
//      Author          : u7
//
//      Last update     : 2023/04/03
//
//      File version    : 4
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * Diecast for creating some sprite data.
**/



/* INCLUDES */
// PRIMARY HEADER
#include "clay_diecast.h"
// C++ SYSTEM HEADER
#include <string>
// PROJECT USING HEADER
#include "src/app/models/mat_benefits.h"
#include "sprite_loader.h"



/* SOURCES */
namespace matter {

    namespace sprite {

        /* using namespace */
        using namespace models;



        implements::IMatBenefits* ClayDiecast::createClay(const std::wstring files) const {
            SpriteLoader* object = new SpriteLoader(files);
            return object;
        }

    }  // namespace sprite

}  // namespace matter