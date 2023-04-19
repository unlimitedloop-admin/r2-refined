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
//      File name       : NEW_APPLICATION_STARTUP.h
//
//      Author          : u7
//
//      Last update     : 2023/04/19
//
//      File version    : 2
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * New application start up trigger.
**/



#ifndef _R2R_DATABASE_TRIGGERS_NEW_APPLICATION_STARTUP_H_
#define _R2R_DATABASE_TRIGGERS_NEW_APPLICATION_STARTUP_H_

/* INCLUDES */
// PROJECT USING HEADER
#include "src/database/tables/TRN_APU_CHANNEL_ENABLED.h"



/* SOURCES */
namespace DB {

    namespace TRIGGER {

        inline void NEW_APPLICATION_STARTUP(void) {
            DB::TRN_APU_CHANNEL_ENABLED::Insert(5U);   // SQ1, SQ2, TRI, NOI, DPCM (5)
        }

    }  // namespace TRIGGER

}  // namespace DB

#endif // !_R2R_DATABASE_TRIGGERS_NEW_APPLICATION_STARTUP_H_