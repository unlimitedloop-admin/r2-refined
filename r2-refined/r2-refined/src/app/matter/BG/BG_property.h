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
//      File name       : BG_property.h
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
 * BG property.header
**/



#ifndef _R2R_APP_MATTER_BG_BG_PROPERTY_H_
#define _R2R_APP_MATTER_BG_BG_PROPERTY_H_

/* INCLUDES */
// PROJECT USING HEADER
#include "src/app/matter/structures/tag_axisation.h"




/* SOURCES */
namespace matter {

    namespace BG {

        /* type defines */
        using diorama = uint_fast32_t;



        /// <summary>
        /// BG tile properties.
        /// </summary>
        typedef struct tagBGProperty {

        public:
            tagBGProperty();
            tagBGProperty(const diorama index);
            ~tagBGProperty() {}

            diorama grids;              // A current location page for grasping the position of the map.
            Axisation vertex;           // Origin to start placing map tiles.

        } BGProperty, *LPBGProperty;

    }  // namespace BG

}  // namespace matter

#endif // !_R2R_APP_MATTER_BG_BG_PROPERTY_H_