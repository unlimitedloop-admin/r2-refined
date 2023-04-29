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
//      File name       : sprite_property.cc
//
//      Author          : u7
//
//      Last update     : 2023/04/29
//
//      File version    : 1
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * sprite property structure.
**/



/* INCLUDES */
// PRIMARY HEADER
#include "sprite_property.h"
// PROJECT USING HEADER
#include "src/app/matter/structures/tag_axisation.h"




/* SOURCES */
namespace matter {

    namespace sprite {

        tagSpriteProperty::tagSpriteProperty() {
            type = Assist::Disabled;
            chip = 0Ui64;
            axis.SetX(0i16);
            axis.SetY(0i16);
            axis.SetZ(0i8);
            transparent = true;
        }

    }  // namespace sprite

}  // namespace matter