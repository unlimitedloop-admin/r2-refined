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
//      Last update     : 2023/05/07
//
//      File version    : 5
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
#include <cstdint>
#include <string>
#include <array>
// PROJECT USING HEADER
#include "mapstruct_loader.h"
#include "src/app/models/mat_benefits.h"
#include "src/app/matter/BG/BG_property.h"
#include "src/app/matter/structures/tag_divgraph_p.h"
#include "src/app/matter/structures/tag_axisation.h"



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
            /// <summary>
            /// A loader class that owns the background tile map structure.
            /// </summary>
            MapstructLoader structure_;

            /// <summary>
            /// An interface pointer that holds a graphic texture.
            /// </summary>
            implements::IMatBenefits* texture_;

            /// <summary>
            /// Drawing information of the map to be placed.
            /// </summary>
            std::array<BGProperty, 4ui64> blueprint_;

        public:
            TileArrays();
            TileArrays(const TileArrays& cc);
            /// <summary>
            /// 
            /// </summary>
            /// <param name="p">Specifies the page position number of the initial array</param>
            TileArrays(const diorama p);
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
            /// <param name="">Void</param>
            /// <returns>True if the drawing was successful</returns>
            bool mappingOn(void);


            /// [blueprint_] Getter, Setter
            inline diorama getGrids(size_t n) { return blueprint_[n].grids; }
            inline void setGrids(size_t n, diorama v) { blueprint_[n].grids = v; }
            inline LPAxisation getVertex(size_t n) { return &blueprint_[n].vertex; }
            inline void setVertex(size_t n, LPAxisation p) { blueprint_[n].vertex = *p; }
            inline int16_t getVertexX(size_t n) { return blueprint_[n].vertex.GetX(); }
            inline void setVertexX(size_t n, int16_t v) { blueprint_[n].vertex.SetX(v); }
            inline int16_t getVertexY(size_t n) { return blueprint_[n].vertex.GetY(); }
            inline void setVertexY(size_t n, int16_t v) { blueprint_[n].vertex.SetY(v); }
            inline int16_t getVertexZ(size_t n) { return blueprint_[n].vertex.GetZ(); }
            inline void setVertexZ(size_t n, int16_t v) { blueprint_[n].vertex.SetZ(v); }

        };

    }  // namespace BG

}  // namespace matter

#endif // !_R2R_APP_MATTER_BG_TILE_ARRAYS_H_