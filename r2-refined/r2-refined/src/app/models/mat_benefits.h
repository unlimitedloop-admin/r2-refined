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
//      File name       : mat_benefits.h
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
 * A set of supporting methods for loading material.
**/



#ifndef _R2R_APP_MODEL_MAT_BENEFITS_H_
#define _R2R_APP_MODEL_MAT_BENEFITS_H_

/* SOURCES */
namespace models {

    namespace implements {

        /// <summary>
        /// An interface that implements the function to position the motion of the material file.
        /// </summary>
        class IMatBenefits {

        public:
            virtual ~IMatBenefits() {}
            virtual bool Unzip(size_t, size_t, size_t, size_t, size_t) = 0;
            virtual bool Use(__int16, __int16, size_t, bool) const = 0;

        };

    }  // namespace implements

}  // namespace models

#endif // !_R2R_APP_MODEL_MAT_BENEFITS_H_