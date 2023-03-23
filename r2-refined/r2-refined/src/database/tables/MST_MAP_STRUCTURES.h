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
//      File name       : MST_MAP_STRUCTURES.h
//
//      Author          : u7
//
//      Last update     : 2023/03/23
//
//      File version    : 1
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * MST_MAP_STRUCTURES table.
**/



#ifndef _R2R_DATABASE_TABLES_MST_MAP_STRUCTURES_H_
#define _R2R_DATABASE_TABLES_MST_MAP_STRUCTURES_H_

/* INCLUDES */
// C++ SYSTEM HEADER
#include <cstdint>



/* SOURCES */
namespace DB {

    namespace MST_MAP_STRUCTURES {

        constexpr uint8_t BIN_HEAD_1 = 0x00;
        constexpr uint8_t BIN_HEAD_2 = 0x01;
        constexpr uint8_t BIN_HEAD_3 = 0x02;
        constexpr uint8_t BIN_HEAD_4 = 0x03;
        constexpr uint8_t ROOM_NUMBR = 0x04;
        constexpr uint8_t CEIL_ROOMS = 0x05;
        constexpr uint8_t UNDER_ROOM = 0x06;
        constexpr uint8_t LEFT_ROOMS = 0x07;
        constexpr uint8_t RIGHT_ROOM = 0x08;
        constexpr uint8_t UD_SCROLLS = 0x09;
        constexpr uint8_t LR_SCROLLS = 0x0A;
        constexpr uint8_t BG_PROPERT = 0x0B;
        constexpr uint8_t PALETTE_NO = 0x0C;
        constexpr uint8_t UNDEFINED1 = 0x0D;
        constexpr uint8_t UNDEFINED2 = 0x0E;
        constexpr uint8_t AGREEMENTS = 0x0F;

    }  // namespace MST_MAP_STRUCTURES

}  // namespace DB

#endif // !_R2R_DATABASE_TABLES_MST_MAP_STRUCTURES_H_