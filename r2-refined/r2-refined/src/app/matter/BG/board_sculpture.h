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
//      File name       : board_sculpture.h
//
//      Author          : u7
//
//      Last update     : 2023/04/01
//
//      File version    : 2
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * board sculpture.header
**/



#ifndef _R2R_APP_MATTER_BG_BOARD_SCULPTURE_H_
#define _R2R_APP_MATTER_BG_BOARD_SCULPTURE_H_

/* INCLUDES */
// PRIMARY HEADER
#include "sculpture.h"
// C++ SYSTEM HEADER
#include <string>
// PROJECT USING HEADER
#include "src/app/models/mat_benefits.h"



/* SOURCES */
namespace matter {

    namespace BG {

        /* using namespace */
        using namespace models;



        /// <summary>
        /// Receiver for passing BG data.
        /// </summary>
        class BoardSculpture : public extends::Sculpture {

        public:
            ~BoardSculpture() {}

            /// <summary>
            /// Generate BG data and get an new instance.
            /// </summary>
            /// <param name="files">File path of the BG data</param>
            /// <returns>Material data common interface object</returns>
            implements::IMatBenefits* createBoard(const std::string files) const override;

        };

    }  // namespace BG

}  // namespace matter

#endif // !_R2R_APP_MATTER_BG_BOARD_SCULPTURE_H_