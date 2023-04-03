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
//      File name       : tile_arrays.h
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
 * tile arrays.header
**/



#ifndef _R2R_APP_MATTER_BG_TILE_ARRAYS_H_
#define _R2R_APP_MATTER_BG_TILE_ARRAYS_H_

/* INCLUDES */
// C++ SYSTEM HEADER
#include <string>
// PROJECT USING HEADER
#include "mapstruct_loader.h"
#include "src/app/models/mat_benefits.h"
#include "src/app/matter/structures/tag_divgraph_p.h"



/* SOURCES */
namespace matter {

    namespace BG {

        /* using namespace */
        using namespace models;


        
        /// <summary>
        /// Management of map tile of texture and binary structure.
        /// </summary>
        class TileArrays {

        private:
            MapstructLoader structure_;
            implements::IMatBenefits* texture_;

        public:
            TileArrays();
            TileArrays(const TileArrays& cc);
            ~TileArrays();

            /// <summary>
            /// Import map data in binary file.
            /// </summary>
            /// <param name="bin_filepath">Filepath</param>
            /// <param name="pages">File capacity in units of 0x100</param>
            /// <returns>True if successfully loaded into memory</returns>
            bool loadStructure(const std::wstring bin_filepath, const size_t pages);

            /// <summary>
            /// Import BG tile data.
            /// </summary>
            /// <param name="filepath">Filepath</param>
            /// <param name="params">Split options</param>
            /// <returns>True if successfully loaded into memory</returns>
            bool loadTexture(const std::wstring filepath, const LPDivGraphParam params);
            
            /// <summary>
            /// BG data read in memory is mapped to VRAM and loaded.
            /// </summary>
            /// <param name="map_no">Capacity number to load</param>
            /// <param name="axis_x">X starting point of the map to start drawing</param>
            /// <param name="axis_y">Y starting point of the map to start drawing</param>
            /// <returns>True if the drawing was successful</returns>
            bool mappingOn(const size_t map_no, const __int16 axis_x, const __int16 axis_y) const;

        };

    }  // namespace BG

}  // namespace matter

#endif // !_R2R_APP_MATTER_BG_TILE_ARRAYS_H_