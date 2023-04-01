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
//      File name       : clay_diecast.h
//
//      Author          : u7
//
//      Last update     : 2023/04/01
//
//      File version    : 3
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * clay diecast.header
**/



#ifndef _R2R_APP_MATTER_SPRITE_CLAY_DIECAST_H_
#define _R2R_APP_MATTER_SPRITE_CLAY_DIECAST_H_

/* INCLUDES */
// PRIMARY HEADER
#include "diecast.h"
// C++ SYSTEM HEADER
#include <string>
// PROJECT USING HEADER
#include "src/app/models/mat_benefits.h"



/* SOURCES */
namespace matter {

    namespace sprite {

        /* using namespace */
        using namespace models;



        /// <summary>
        /// Receiver for passing sprite data.
        /// </summary>
        class ClayDiecast : public extends::Diecast {

        public:
            ~ClayDiecast() {}
            
            /// <summary>
            /// Generate sprite data and get an new instance.
            /// </summary>
            /// <param name="files">File path of the sprite data to get</param>
            /// <returns>Material data common interface object</returns>
            implements::IMatBenefits* createClay(const std::string files) const override;

        };

    }  // namespace sprite

}  // namespace matter

#endif // !_R2R_APP_MATTER_SPRITE_CLAY_DIECAST_H_