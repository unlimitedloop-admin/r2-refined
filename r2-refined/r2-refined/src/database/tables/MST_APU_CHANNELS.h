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
//      File name       : MST_APU_CHANNELS.h
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
 * MST_APU_CHANNELS table.
**/



#ifndef _R2R_DATABASE_TABLES_MST_APU_CHANNELS_H_
#define _R2R_DATABASE_TABLES_MST_APU_CHANNELS_H_

/* INCLUDES */
// C++ SYSTEM HEADER
#include <cstdint>
#include <vector>
#include <string>



/* SOURCES */
namespace {

    /// <summary>
    /// CREATE TABLE MST_APU_CHANNELS.
    /// </summary>
    struct tagMSTApuChannels {
        std::string name;
        uint8_t value;
    };

    /// <summary>
    /// INSERT INTO MST_APU_CHANNELS.
    /// </summary>
    const std::vector<tagMSTApuChannels> MST_APU_CHANNELS = {
        {"APU_CH_SQUARE_1", 1U},
        {"APU_CH_SQUARE_2", 2U},
        {"APU_CH_TRIANGLE", 4U},
        {"APU_CH_NOISE_BG", 8U},
        {"APU_CH_DELTAPCM", 16U}
    };

}  // local scope



namespace DB {

    namespace APU_CHANNELS {

        /// <summary>
        /// MST_APU_CHANNELS size.
        /// </summary>
        /// <param name="">Void</param>
        /// <returns>Size of MST_APU_CHANNELS</returns>
        inline size_t Count(void) {
            return MST_APU_CHANNELS.size();
        }


        /// <summary>
        /// Get the MST_APU_CHANNELS value.
        /// </summary>
        /// <param name="name">The name of the object to retrieve</param>
        /// <returns></returns>
        inline uint8_t selectValue(const std::string name) {
            for (const auto& v : MST_APU_CHANNELS) {
                if (name == v.name) { return v.value; }
            }
            return 0Ui8;
        }


        inline size_t Rows(const std::string name) {
            for (const auto& v : MST_APU_CHANNELS) {
                if (name == v.name) { return &v - &MST_APU_CHANNELS[0]; }
            }
            return 0Ui64;
        }

    }  // namespace MST_APU_CHANNELS

}  // namespace DB

#endif // !_R2R_DATABASE_TABLES_MST_APU_CHANNELS_H_