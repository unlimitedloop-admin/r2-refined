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
//      File name       : sprite_property.h
//
//      Author          : u7
//
//      Last update     : 2023/05/07
//
//      File version    : 2
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * sprite property.header
**/



#ifndef _R2R_APP_MATTER_SPRITE_SPRITE_PROPERTY_H_
#define _R2R_APP_MATTER_SPRITE_SPRITE_PROPERTY_H_

/* INCLUDES */
// PROJECT USING HEADER
#include "src/app/matter/structures/tag_axisation.h"




/* SOURCES */
namespace matter {

    namespace sprite {

        enum class Assist {
            Disabled
            , Superior
            , Influence
            , Inferior
            , Automatic
        };



        typedef struct tagSpriteProperty {

        public:
            tagSpriteProperty();
            ~tagSpriteProperty() {}
            
            Assist type;                // Authority.
            size_t chip;                // Object tile number.
            Axisation axis;             // Object position information.
            bool transparent;           // Whether the object is transparent.


            // TODO : Getter, Setter.

        } SpriteProperty, *LPSpriteProperty;

    }  // namespace sprite

}  // namespace matter

#endif // !_R2R_APP_MATTER_SPRITE_SPRITE_PROPERTY_H_