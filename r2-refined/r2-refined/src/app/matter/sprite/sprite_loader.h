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
//      File name       : sprite_loader.h
//
//      Author          : u7
//
//      Last update     : 2023/03/11
//
//      File version    : 1
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * sprite loader.header
**/



#ifndef _R2R_APP_MATTER_SPRITE_SPRITE_LOADER_H_
#define _R2R_APP_MATTER_SPRITE_SPRITE_LOADER_H_

/* INCLUDES */
// PRIMARY HEADER
#include "src/app/models/loader.h"
// C++ SYSTEM HEADER
#include <vector>
#include <string>



/* SOURCES */
namespace matter {

    namespace sprite {

        /* using namespace */
        using namespace models;


        /// <summary>
        /// A loader that reads and manages sprite data.
        /// </summary>
        class SpriteLoader : public extends::Loader {

        private:
            /// <summary>
            /// Sprite data handler.
            /// </summary>
            std::vector<int> graphics_;

        public:
            SpriteLoader(std::string filepath);
            ~SpriteLoader();

            /// <summary>
            /// Loads a sprite data image into memory with the specified tiling options.
            /// </summary>
            /// <param name="all_num">Quantity of tiles</param>
            /// <param name="x_num">Number of tiles to divide horizontally</param>
            /// <param name="y_num">Number of tiles to split vertically</param>
            /// <param name="x_size">Size of one tile(width)</param>
            /// <param name="y_size">Size of one tile(height)</param>
            /// <returns>True if loaded into memory successfully, false otherwise</returns>
            bool Unzip(size_t all_num, size_t x_num, size_t y_num, size_t x_size, size_t y_size);

            /// <summary>
            /// Draw sprite data loaded in memory.
            /// </summary>
            /// <param name="x">The X coordinate point of the destination screen</param>
            /// <param name="y">The Y coordinate point of the destination screen</param>
            /// <param name="t_num">Tile label no. to draw</param>
            /// <param name="transparent">Specify true if the image should be transparent</param>
            /// <returns>True if draw to the screen successfully, false otherwise</returns>
            bool Use(__int16 x, __int16 y, size_t t_num, bool transparent) const;
        };

    }  // namespace sprite

}  // namespace matter

#endif // !_R2R_APP_MATTER_SPRITE_SPRITE_LOADER_H_