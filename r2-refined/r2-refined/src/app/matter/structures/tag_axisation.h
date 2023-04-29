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
//      File name       : tag_axisation.h
//
//      Author          : u7
//
//      Last update     : 2023/04/29
//
//      File version    : 1
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * A variable set that manages coordinate points.
**/



#ifndef _R2R_APP_MATTER_STRUCTURES_TAG_AXISATION_H_
#define _R2R_APP_MATTER_STRUCTURES_TAG_AXISATION_H_

/* INCLUDES */
// C++ SYSTEM HEADER
#include <cstdint>



/* SOURCES */
namespace matter {

    /// <summary>
    /// A member structure that manages coordinates on the screen.
    /// </summary>
    typedef struct tagAxisation {

    private:
        int16_t x = 0i16;
        int16_t y = 0i16;
        int8_t  z = 0i8;

    public:
        void SetX(int16_t v) {
            x = v;
        }

        int16_t GetX(void) {
            return x;
        }

        void SetY(int16_t v) {
            y = v;
        }

        int16_t GetY(void) {
            return y;
        }

        void SetZ(int8_t v) {
            z = v;
        }

        int8_t GetZ(void) {
            return z;
        }

    } Axisation;

}  // namespace matter

#endif // !_R2R_APP_MATTER_STRUCTURES_TAG_AXISATION_H_