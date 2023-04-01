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
//      File name       : MST_APU_CHANNELS_VIEW.h
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



#ifndef _R2R_DATABASE_VIEWS_MST_APU_CHANNELS_VIEW_H_
#define _R2R_DATABASE_VIEWS_MST_APU_CHANNELS_VIEW_H_

/* INCLUDES */
// C++ SYSTEM HEADER
#include <cstdint>
#include <vector>



/* SOURCES */
namespace DB {

    namespace APU_CHANNELS_VIEW {

    /// <summary>
    /// Returns identifiers for all sound source channels.
    /// </summary>
    /// <param name="">Void</param>
    /// <returns>ID</returns>
    extern uint8_t allApuChannel(void);

    /// <summary>
    /// Sound channel list.
    /// </summary>
    /// <param name="">Void</param>
    /// <returns>Vector list</returns>
    extern std::vector<uint8_t> arrayList(void);

    }  // namespace APU_CHANNELS

}  // namespace DB

#endif // !_R2R_DATABASE_VIEWS_MST_APU_CHANNELS_VIEW_H_