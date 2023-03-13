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
//      File name       : diecast.h
//
//      Author          : u7
//
//      Last update     : 2023/03/13
//
//      File version    : 1
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



        implements::IMatBenefits* ClayDiecast::createClay(std::string files) {
            SpriteLoader* object = new SpriteLoader(files);
            return object;
        }

    }  // namespace sprite

}  // namespace matter