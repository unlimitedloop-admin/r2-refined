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
//      File name       : echo_benefits.h
//
//      Author          : u7
//
//      Last update     : 2023/04/01
//
//      File version    : 1
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * A set of supporting methods for loading acoustic sound data.
**/



#ifndef _R2R_APP_MODELS_ECHO_BENEFITS_H_
#define _R2R_APP_MODELS_ECHO_BENEFITS_H_

/* INCLUDES */
// C++ SYSTEM HEADER
#include <cstdint>



/* SOURCES */
namespace models {

    namespace implements {

        /// <summary>
        /// An interface that implements the function to position the motion of the sound file.
        /// </summary>
        class IEchoBenefits {

        public:
            virtual ~IEchoBenefits() {}
            virtual bool Unzip(uint8_t) = 0;
            virtual bool Play(uint8_t, bool) const = 0;
            virtual bool Stop(uint8_t) const = 0;
            virtual bool Del(uint8_t) const = 0;
            virtual bool changeVolume(size_t, size_t) = 0;
            virtual bool setMusicNotation(uint8_t, size_t, size_t, size_t) = 0;
            virtual bool checkNowPlaying(uint8_t) const = 0;
            virtual uint8_t getLouder(size_t) const = 0;

        };

    }  // namespace implements

}  // namespace models

#endif // !_R2R_APP_MODELS_ECHO_BENEFITS_H_