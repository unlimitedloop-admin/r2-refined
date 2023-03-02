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
//      File name       : hardware_check.cc
//
//      Author          : u7
//
//      Last update     : 2023/02/17
//
//      File version    : 3
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * hardware check and application boot-up commander.
**/



/* INCLUDES */
// GENERAL USING HEADER
#include <Windows.h>
#include <VersionHelpers.h>
// PROJECT USING HEADER
#include "src/protocol/process_code_hard.h"



/* SOURCES */
namespace {

    constexpr __int32 ARCHITECTURE_CHECK_OK = 0;
    constexpr __int32 ARCHITECTURE_CHECK_NG = -1;

}  // plain namespace



namespace boot {

    typedef NTSTATUS(WINAPI* RtlGetVersionPtr)(PRTL_OSVERSIONINFOW lpVersionInformation);

    bool checkingSystemInfo(void) {
        auto checker = 0;

        // Checking for hardware processors.
        SYSTEM_INFO system_info;
        GetNativeSystemInfo(&system_info);
        switch (system_info.wProcessorArchitecture) {
        case PROCESSOR_ARCHITECTURE_AMD64:
        case PROCESSOR_ARCHITECTURE_ARM:
        case PROCESSOR_ARCHITECTURE_ARM64:
        case PROCESSOR_ARCHITECTURE_INTEL:
            checker = ARCHITECTURE_CHECK_OK;
            break;
        default:
            checker = ARCHITECTURE_CHECK_NG;
            break;
        }
        if (checker) {
            setStaticProcessCode(0x0002B1ULL, STATIC_ERR_DOMINATOR);
            return false;
        }

        // This application is only supported on Windows 7 or later OS.
        if (!IsWindows7OrGreater()) {
            setStaticProcessCode(0x0003B1ULL, STATIC_ERR_DOMINATOR);
            return false;
        }

        // Checking whether RAM capacity of 256MB or over can be allocated.
        MEMORYSTATUSEX mem_status{};
        mem_status.dwLength = sizeof(mem_status);
        GlobalMemoryStatusEx(&mem_status);
        if ((DWORDLONG)0xFF72D80 >= mem_status.ullTotalPhys) {
            setStaticProcessCode(0x0004B1ULL, STATIC_ERR_DOMINATOR);
            return false;
        }

        return true;
    }

}  // namespace boot