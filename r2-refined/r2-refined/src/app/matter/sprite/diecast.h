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
//      File name       : diecast.h
//
//      Author          : u7
//
//      Last update     : 2023/03/13
//
//      File version    : 1
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * Diecast for creating some object data.
**/



#ifndef _R2R_APP_MATTER_SPRITE_DIECAST_H_
#define _R2R_APP_MATTER_SPRITE_DIECAST_H_

/* INCLUDES */
// C++ SYSTEM HEADER
#include <string>
// PROJECT USING HEADER
#include "src/app/models/mat_benefits.h"



/* SOURCES */
namespace matter {

    namespace sprite {

        namespace extends {

            /* using namespace */
            using namespace models;



            /// <summary>
            /// Factory method class for creating graphic instances.
            /// </summary>
            class Diecast {

            protected:
                virtual implements::IMatBenefits* createClay(std::string files) = 0;

            public:
                virtual ~Diecast() {}
                
                /// <summary>
                /// Factory class for creating sprite data.
                /// </summary>
                /// <param name="files">File path of the sprite data to get</param>
                /// <returns>Product of sprite data</returns>
                virtual implements::IMatBenefits* Create(std::string files) {
                    implements::IMatBenefits* object = createClay(files);
                    return object;
                }

            };

        }  // namespace extends

    }  // namespace sprite

}  // namespace matter

#endif // !_R2R_APP_MATTER_SPRITE_DIECAST_H_