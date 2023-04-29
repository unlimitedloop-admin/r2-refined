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
//      Last update     : 2023/04/29
//
//      File version    : 4
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
#include "sprite_property.h"




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
            /// Sprite bank data option.
            /// </summary>
            std::map<std::wstring, SpriteProperty> status_;

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
            /// <returns>True if successfully drawn to the window</returns>
            bool Draw(const std::wstring name);

        };

    }  // namespace sprite

}  // namespace matter

#endif // !_R2R_APP_MATTER_SPRITE_SPRITE_BANK_H_