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
//      File name       : trn_apu_channel_enabled.cc
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
 * TRN_APU_CHANNEL_ENABLED table.
**/



/* SOURCES */
namespace {

    /// <summary>
    /// APU sound channels.
    /// </summary>
    __int8 value = 0;

}  // local scope



namespace DB {

    namespace TRN_APU_CHANNEL_ENABLED {

        __int8 Select(void) { return value; }

        void Insert(__int8 v) { value = v; }

    }  // namespace TRN_APU_CHANNEL_ENABLED

}  // namespace DB