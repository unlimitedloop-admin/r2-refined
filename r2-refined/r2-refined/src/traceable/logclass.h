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
//      File name       : logclass.h
//
//      Author          : u7
//
//      Last update     : 2023/02/08
//
//      File version    : 1
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * An enum class that indicates the log severity.
**/



#ifndef _R2R_TRACEABLE_LOGCLASS_H_
#define _R2R_TRACEABLE_LOGCLASS_H_

/* SOURCES */
namespace traceable {

    /// <summary>
    /// Defines the hierarchy of log file output sources.
    /// </summary>
    enum class LogClass {
        LOG_LEVEL_OFF
        , LOG_LEVEL_TRACE
        , LOG_LEVEL_DEBUG
        , LOG_LEVEL_INFO
        , LOG_LEVEL_WARN
        , LOG_LEVEL_ERROR
        , LOG_LEVEL_CRITICAL
        , LOG_LEVEL_UNKNOWN = 9
    };

    constexpr LogClass default_prclog_level = LogClass::LOG_LEVEL_TRACE;
    constexpr LogClass default_errlog_level = LogClass::LOG_LEVEL_ERROR;

}  // namespace traceable

#endif // !_R2R_TRACEABLE_LOGCLASS_H_