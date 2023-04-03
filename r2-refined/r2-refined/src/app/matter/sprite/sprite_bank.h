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
//      File name       : sprite_bank.h
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
 * sprite bank.header
**/



#ifndef _R2R_APP_MATTER_SPRITE_SPRITE_BANK_H_
#define _R2R_APP_MATTER_SPRITE_SPRITE_BANK_H_

/* INCLUDES */
// C++ SYSTEM HEADER
#include <string>
#include <map>
// PROJECT USING HEADER
#include "src/app/models/mat_benefits.h"
#include "src/app/matter/structures/tag_divgraph_p.h"




/* SOURCES */
namespace matter {

    namespace sprite {

        /* using namespace */
        using namespace models;



        /// <summary>
        /// Management of sprite of texture.
        /// </summary>
        class SpriteBank {

        private:
            /// <summary>
            /// Sprite bank object.
            /// </summary>
            std::map<std::wstring, implements::IMatBenefits*> objects_;

        public:
            SpriteBank();
            SpriteBank(const SpriteBank& cc);
            ~SpriteBank();

            /// <summary>
            /// Divides the specified sprite data and takes it into memory.
            /// </summary>
            /// <param name="name">Specify the title that identifies the sprites to import</param>
            /// <param name="filepath">Filepath to import</param>
            /// <param name="params">Split options</param>
            /// <returns>True if successfully loaded into memory</returns>
            bool Push(const std::wstring name, const std::wstring filepath, const LPDivGraphParam params);

            /// <summary>
            /// Draw the loaded sprite image to the screen.
            /// </summary>
            /// <param name="name">Sprite names</param>
            /// <param name="tile_num">Specify the order of tiles to draw</param>
            /// <param name="x">The X coordinate position of the screen to draw</param>
            /// <param name="y">The Y coordinate position of the screen to draw</param>
            /// <param name="transparent">Whether the rendered image should be transparent</param>
            /// <returns>True if successfully drawn to the window</returns>
            bool Draw(const std::wstring name, const size_t tile_num, const __int16 x, const __int16 y, const bool transparent) const;

        };

    }  // namespace sprite

}  // namespace matter

#endif // !_R2R_APP_MATTER_SPRITE_SPRITE_BANK_H_