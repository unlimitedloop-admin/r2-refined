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
//      File name       : NEW_APPLICATION_START_UP.h
//
//      Author          : u7
//
//      Last update     : 2023/04/11
//
//      File version    : 1
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * New application start up trigger.
**/



#ifndef _R2R_DATABASE_PROGRAMMINGS_TRIGGERS_NEW_APPLICATION_START_UP_H_
#define _R2R_DATABASE_PROGRAMMINGS_TRIGGERS_NEW_APPLICATION_START_UP_H_

/* INCLUDES */
// PROJECT USING HEADER
#include "src/database/tables/TRN_APU_CHANNEL_ENABLED.h"



/* SOURCES */
namespace DB {

    namespace programmings {

        inline void newApplicationStartUpTrigger(void) {
            DB::TRN_APU_CHANNEL_ENABLED::Insert(5U);   // SQ1, SQ2, TRI, NOI, DPCM (5)
        }

    }  // namespace programmings

}  // namespace DB

#endif // !_R2R_DATABASE_PROGRAMMINGS_TRIGGERS_NEW_APPLICATION_START_UP_H_