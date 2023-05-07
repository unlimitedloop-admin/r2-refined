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
//      File name       : unified_action.h
//
//      Author          : u7
//
//      Last update     : 2023/05/07
//
//      File version    : 1
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * unified action.header
**/



#ifndef _R2R_APP_ALGORITHM_ACTION_SYSTEM_UNIFIED_ACTION_H_
#define _R2R_APP_ALGORITHM_ACTION_SYSTEM_UNIFIED_ACTION_H_

/* INCLUDES */
// PRIMARY HEADER
#include "src/app/models/employee.h"
// PROJECT USING HEADER
#include "src/app/matter/blending/dealer.h"



/* SOURCES */
namespace algorithm {

    namespace action_system {

        /* using namespace */
        using namespace models;



        /// <summary>
        /// A class that encapsulates the behavior of the action_system.
        /// </summary>
        class UnifiedAction : public implements::IEmployee {

        public:
            UnifiedAction();
            ~UnifiedAction();

            /// <summary>
            /// Do the work of the action mechanism collectively.
            /// </summary>
            /// <param name="impl">Meterial object instance</param>
            /// <returns>True if the operation was successful</returns>
            bool Work(matter::blending::Dealer* impl) override;

        };

    }  // namespace action_system

}  // namespace algorithm

#endif // !_R2R_APP_ALGORITHM_ACTION_SYSTEM_UNIFIED_ACTION_H_