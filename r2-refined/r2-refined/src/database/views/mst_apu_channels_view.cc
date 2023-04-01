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
//      File name       : MST_APU_CHANNELS_VIEW.cc
//
//      Author          : u7
//
//      Last update     : 2023/04/01
//
//      File version    : 1
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * MST_APU_CHANNELS_VIEW view.
**/



/* INCLUDES */
// PRIMARY HEADER
#include "src/database/tables/MST_APU_CHANNELS.h"
// C++ SYSTEM HEADER
#include <vector>



/* SOURCES */
namespace DB {

    namespace APU_CHANNELS_VIEW {

        uint8_t allApuChannel(void) {
            uint8_t ret = 0U;
            for (const auto& v : MST_APU_CHANNELS) {
                ret = ret + v.value;
            }
            return ret;
        }


        std::vector<uint8_t> arrayList(void) {
            std::vector<uint8_t> list = {};
            for (const auto& v : MST_APU_CHANNELS) {
                list.push_back(v.value);
            }
            return list;
        }

    }  // namespace APU_CHANNELS

}  // namespace DB