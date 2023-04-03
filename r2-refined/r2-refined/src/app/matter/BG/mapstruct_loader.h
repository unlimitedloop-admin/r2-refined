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
//      File name       : mapstruct_loader.h
//
//      Author          : u7
//
//      Last update     : 2023/04/03
//
//      File version    : 4
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * mapstruct loader.header
**/



#ifndef _R2R_APP_MATTER_BG_MAPSTRUCT_LOADER_H_
#define _R2R_APP_MATTER_BG_MAPSTRUCT_LOADER_H_

/* INCLUDES */
// C++ SYSTEM HEADER
#include <vector>
#include <string>
// GENERAL USING HEADER
#include <Windows.h>



/* SOURCES */
namespace matter {

    namespace BG {

        /// <summary>
        /// A class that manages the structure for importing binary data.
        /// </summary>
        class MapstructLoader {

        private:
            /// <summary>
            /// Binary data covered.
            /// </summary>
            std::vector<BYTE> data_;

            /// <summary>
            /// A number within a block of 0x100.
            /// </summary>
            size_t all_page_;

        public:
            MapstructLoader() : data_(0), all_page_(0) {}
            ~MapstructLoader();

            /// <summary>
            /// Load map data into memory, this must be a binary file.
            /// </summary>
            /// <param name="filepath">File path of the binary file</param>
            /// <param name="pages">Specify how many pages to import, with 0x100 as one page</param>
            /// <returns>True is fetched successfully</returns>
            bool Loading(const std::wstring filepath, const size_t pages);

            /// <summary>
            /// Get the set number of pages.
            /// </summary>
            /// <param name="">Void</param>
            /// <returns>Page numbers</returns>
            size_t getAllPage(void) const;

            /// <summary>
            /// Get binary data in memory (how to specify original array).
            /// </summary>
            /// <param name="page">The page position to retrieve</param>
            /// <param name="num">Index of the binary data to retrieve</param>
            /// <returns>Hex code</returns>
            BYTE getData(const size_t page, const size_t num) const;

            /// <summary>
            /// Get binary data in memory (Map format).
            /// </summary>
            /// <param name="page">The page position to retrieve</param>
            /// <param name="row_num">Lines</param>
            /// <param name="col_num">Column Index</param>
            /// <returns>Hex code</returns>
            BYTE getMapData(const size_t page, const size_t row_num, const size_t col_num) const;

            /// <summary>
            /// Get head information of binary data in memory.
            /// </summary>
            /// <param name="page">The page position to retrieve</param>
            /// <param name="block">A constant value of DB::MST_MAP_STRUCTURES</param>
            /// <returns>Hex code</returns>
            BYTE getHeadData(const size_t page, const uint8_t block) const;

        };

    }  // namespace BG

}  // namespace matter

#endif // !_R2R_APP_MATTER_BG_MAPSTRUCT_LOADER_H_