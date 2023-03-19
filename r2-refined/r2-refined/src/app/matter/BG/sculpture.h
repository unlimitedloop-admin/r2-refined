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
//      File name       : sculpture.h
//
//      Author          : u7
//
//      Last update     : 2023/03/19
//
//      File version    : 1
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * Create by drawing on several boards.
**/



#ifndef _R2R_APP_MATTER_BG_SCULPTURE_H_
#define _R2R_APP_MATTER_BG_SCULPTURE_H_

/* INCLUDES */
// C++ SYSTEM HEADER
#include <string>
// PROJECT USING HEADER
#include "src/app/models/mat_benefits.h"



/* SOURCES */
namespace matter {

    namespace BG {

        namespace extends {

            /* using namespace */
            using namespace models;



            /// <summary>
            /// Factory method class for creating BG tile objects.
            /// </summary>
            class Sculpture {

            protected:
                virtual implements::IMatBenefits* createBoard(std::string files) = 0;

            public:
                virtual ~Sculpture() {}

                /// <summary>
                /// Factory class for creating BG tile data.
                /// </summary>
                /// <param name="files">File path of the BG tile data to get</param>
                /// <returns>Product of BG tile data</returns>
                virtual implements::IMatBenefits* Create(std::string files) {
                    implements::IMatBenefits* object = createBoard(files);
                    return object;
                }

            };

        }  // namespace extends

    }  // namespace BG

}  // namespace matter


#endif // !_R2R_APP_MATTER_BG_SCULPTURE_H_