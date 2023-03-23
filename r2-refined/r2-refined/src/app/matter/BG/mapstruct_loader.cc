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
//      File name       : mapstruct_loader.cc
//
//      Author          : u7
//
//      Last update     : 2023/03/23
//
//      File version    : 2
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * Implements the class that manages the structure forr importing binary data.
**/



/* INCLUDES */
// PRIMARY HEADER
#include "mapstruct_loader.h"
// C++ SYSTEM HEADER
#include <string>
#include <fstream>
// GENERAL USING HEADER
#include <Windows.h>
// PROJECT USING HEADER
#include "src/exceptions/exception_handler.h"
#include "src/protocol/process_code_hard.h"
#include "src/protocol/xglobals.h"
#include "src/database/tables/MST_MAP_STRUCTURES.h"



/* SOURCES */
namespace matter {

    namespace BG {

        MapstructLoader::~MapstructLoader() {
            data_.clear();
            data_.shrink_to_fit();
        }


        bool MapstructLoader::Loading(const std::string filepath, const size_t pages) {
            try {
                if (std::ifstream dat(filepath, std::ios::in | std::ios::binary); dat.fail()) {
                    setStaticProcessCode(0x00E5F1ULL, STATIC_ERR_DOMINATOR);
                    NATIVE_MSG("#Bad tried file open: %s", filepath.c_str());
                    return false;
                }
                else {
                    dat.unsetf(std::ios::skipws);
                    data_.reserve(0x100 * pages);
                    data_.insert(data_.begin(), std::istream_iterator<BYTE>(dat), std::istream_iterator<BYTE>());   // Insert all binary data.
                    all_page_ = pages;
                }
            }
            catch (std::exception& e) {
                xg_exChar = e.what();
                setStaticProcessCode(0x0000F1ULL, STATIC_ERR_DOMINATOR);
                return false;
            }
            return true;
        }


        size_t MapstructLoader::getAllPage(void) {
            return all_page_;
        }


        BYTE MapstructLoader::getData(const size_t page, const size_t num) const {
            size_t loc = 0x100 * (page - 1);
            return data_[(loc + num)];
        }


        BYTE MapstructLoader::getMapData(const size_t page, const size_t row_num, const size_t col_num) const {
            size_t loc = 0x100 * (page - 1);
            loc = loc + 0x10 + (0x10 * row_num) + col_num;  // Skip the head data (0x10) and specify the number of rows and column position in the area after that with 0x10 separators.
            return data_[loc];
        }


        BYTE MapstructLoader::getHeadData(const size_t page, const uint8_t block) const {
            return this->getData(page, static_cast<size_t>(block));
        }

    }  // namespace BG

}  // namespace matter