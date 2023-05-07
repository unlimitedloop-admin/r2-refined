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
//      File name       : dealer.h
//
//      Author          : u7
//
//      Last update     : 2023/05/07
//
//      File version    : 1
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * dealer.header
**/



#ifndef _R2R_APP_MATTER_BLENDING_DEALER_H_
#define _R2R_APP_MATTER_BLENDING_DEALER_H_

/* INCLUDES */
// PROJECT USING HEADER
#include "src/app/matter/sprite/sprite_bank.h"
#include "src/app/matter/BG/tile_arrays.h"
#include "src/app/matter/sound/audio_equipment.h"



/* SOURCES */
namespace matter {

    namespace blending {

        class Dealer final {

        public:
            Dealer();
            //Dealer(const Dealer&);    // Maybe it don't need?
            ~Dealer();

            sprite::SpriteBank SPRITE;
            BG::TileArrays BG;
            sound::AudioEquipment SOUND;

        };
       
    }  // namespace blending

}  // namespace matter

#endif // !_R2R_APP_MATTER_BLENDING_DEALER_H_