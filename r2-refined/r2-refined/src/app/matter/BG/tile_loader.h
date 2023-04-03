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
//      File name       : tile_loader.h
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
 * tile loader.header
**/



#ifndef _R2R_APP_MATTER_BG_TILE_LOADER_H_
#define _R2R_APP_MATTER_BG_TILE_LOADER_H_

/* INCLUDES */
// PRIMARY HEADER
#include "src/app/models/loader.h"
#include "src/app/models/mat_benefits.h"
// C++ SYSTEM HEADER
#include <vector>
#include <string>



/* SOURCES */
namespace matter {

    namespace BG {

        /// <summary>
        /// A loader that reads and manages BG tile data.
        /// </summary>
        class TileLoader : public models::extends::Loader, public models::implements::IMatBenefits {

        private:
            /// <summary>
            /// Sprite data handler.
            /// </summary>
            std::vector<int> graphics_;

        public:
            TileLoader(const std::wstring filepath);
            ~TileLoader();

            /// <summary>
            /// Loads a BG data image into memory with the specified tiling options.
            /// </summary>
            /// <param name="all_num">Quantity of tiles</param>
            /// <param name="x_num">Number of tiles to divide horizontally</param>
            /// <param name="y_num">Number of tiles to split vertically</param>
            /// <param name="x_size">Size of one tile(width)</param>
            /// <param name="y_size">Size of one tile(height)</param>
            /// <returns>True if loaded into memory successfully, false otherwise</returns>
            bool Unzip(const size_t all_num, const size_t x_num, const size_t y_num, const size_t x_size, const size_t y_size) override;

            /// <summary>
            /// Draw BG data loaded in memory.
            /// </summary>
            /// <param name="x">The X coordinate point of the destination screen</param>
            /// <param name="y">The Y coordinate point of the destination screen</param>
            /// <param name="t_num">Tile label no. to draw</param>
            /// <param name="transparent">Specify true if the image should be transparent</param>
            /// <returns>True if draw to the screen successfully, false otherwise</returns>
            bool Use(const __int16 x, const __int16 y, const size_t t_num, const bool transparent) const override;

        };

    }  // namespace BG

}  // namespace matter

#endif // !_R2R_APP_MATTER_BG_TILE_LOADER_H_