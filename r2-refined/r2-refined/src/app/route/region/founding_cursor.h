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
//      File name       : founding_cursor.h
//
//      Author          : u7
//
//      Last update     : 2023/03/11
//
//      File version    : 1
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * When the main program is new, store the first reference container.
**/



#ifndef _R2R_APP_ROUTE_REGION_FOUNDING_CURSOR_H_
#define _R2R_APP_ROUTE_REGION_FOUNDING_CURSOR_H_

/* INCLUDES */
// PROJECT USING HEADER
#include "src/app/models/components.h"
#include "src/app/component/AX/A1_launch/launching_component.h"



/* SOURCES */
namespace route {

    namespace region {

        /* using namespace */
        using namespace models;




        /// <summary>
        /// Cursor class at the time of foundation.
        /// </summary>
        class FoundingCursor final {

        public:
            FoundingCursor() {}
            ~FoundingCursor() {}

            /// <summary>
            /// Get the cursor instance.
            /// </summary>
            /// <param name="">Void</param>
            /// <returns>The cursor instance</returns>
            implements::IComponents* getComponents(void);

        };


        
        inline implements::IComponents* FoundingCursor::getComponents(void) {
            /* Immediately after the program is executed, specify the cursor to be executed first. */
            return new component::A1_launch::LaunchingComponent();
        }

    }  // namespace region

}  // namespace route

#endif // !_R2R_APP_ROUTE_REGION_FOUNDING_CURSOR_H_