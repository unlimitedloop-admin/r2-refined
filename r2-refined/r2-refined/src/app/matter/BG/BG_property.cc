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
//      File name       : BG_property.cc
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
 * Background property structure.
**/



/* INCLUDES */
// PRIMARY HEADER
#include "BG_property.h"




/* SOURCES */
namespace matter {

    namespace BG {

        tagBGProperty::tagBGProperty() {
            grids = NULL;
            vertex = {};
        }


        tagBGProperty::tagBGProperty(const diorama index) {
            grids = index;
            vertex = {};
        }

    }  // namespace BG

}  // namespace matter