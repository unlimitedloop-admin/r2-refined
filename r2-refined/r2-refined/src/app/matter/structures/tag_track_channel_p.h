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
//      File name       : tag_track_channel_p.h
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
 * Defines the channel for the NES sound APU.
**/



#ifndef _R2R_APP_MATTER_STRUCTURES_TAG_TRACK_CHANNEL_P_H_
#define _R2R_APP_MATTER_STRUCTURES_TAG_TRACK_CHANNEL_P_H_

/* INCLUDES */
// C++ SYSTEM HEADER
#include <string>



/* SOURCES */
namespace matter {

    typedef struct tagTrackChannelParam {
    public:
        std::string square1;
        std::string square2;
        std::string triangle;
        std::string noise;
        std::string DPCM;
    } TrackChannelParam, * LPTrackChannelParam;

}  // namespace matter

#endif // !_R2R_APP_MATTER_STRUCTURES_TAG_TRACK_CHANNEL_P_H_