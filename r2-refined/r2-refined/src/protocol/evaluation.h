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
//      File name       : evaluation.h
//
//      Author          : u7
//
//      Last update     : 2023/02/18
//
//      File version    : 2
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * System parameters that are common across applications,
 * and a cluster of global enums.
**/



#ifndef _R2R_PROTOCOL_EVALUATION_H_
#define _R2R_PROTOCOL_EVALUATION_H_

/* SOURCES */
namespace protocol {

    /// <summary>
    /// Generic result set.
    /// </summary>
    enum class ResultSet {
        DISABLED
        , ENABLED
    };


    /// <summary>
    /// A type of application run mode.
    /// </summary>
    enum class RunMode {
        GENERAL_MODE
        , DEBUG_MODE
    };


    /// <summary>
    /// This is the execution result list of the main program. SUCCEED (successful), FAILED (error), or QUIT for exit.
    /// </summary>
    enum class Evaluate {
        PROC_FAILED = -1
        , PROC_SUCCEED
        , PROC_QUIT
    };


    /// <summary>
    /// Application activator.
    /// </summary>
    enum class Activator {
        DISABLED = -1
        , NOT_ACTIVATION
        , CHANGE_MAINPROC
        , CHANGE_DEVELOPPROC
    };

}  // namespace protocol

#endif // !_R2R_PROTOCOL_EVALUATION_H_