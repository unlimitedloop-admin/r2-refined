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
//      File name       : errorlist_0x00x.cc
//
//      Author          : u7
//
//      Last update     : 2023/02/17
//
//      File version    : 1
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * Error list corresponding to error code 0x0000 to 0x00FF.
**/



/* INCLUDES */
// PRIMARY HEADER
#include "errorlist_0x00x.h"
// C++ SYSTEM HEADER
#include <string>
#include <sstream>
#include <iomanip>
// GENERAL USING HEADER
#include <Windows.h>
// PROJECT USING HEADER
#include "src/traceable/output_logs.h"



/* SOURCES */
namespace exceptions {

    /* using namespace */
    using namespace traceable;



    std::string ErrorList0x00x::What(unsigned __int64 error_code, LogClass level) {
        std::ostringstream message;
        const std::string str_crlf = "\r\n";
        message << "発生したエラーコードは：[" << "0x" << std::setw(6) << std::hex << std::uppercase << std::setfill('0') << error_code << "] です。";
        (void)writeErrorLog(message.str(), "エラーコード");
        message.str(""); message.clear();

        switch (error_code / 0x000100ULL) {
        case 0x0001ULL:
            message << "環境変数取得処理で不明なエラーが発生したため、アプリケーションの実行は中断されます。";
            break;
        case 0x0002ULL:
            message << "インストールされているオペレーティング・システムの不明なプロセッサ・アーキテクチャが返却されました。";
            break;
        case 0x0003ULL:
            message << "Windows 7以前のOSは動作対象外です。";
            break;
        case 0x0004ULL:
            message << "メモリ領域に十分な空き領域がないためアプリケーションは開始されません。";
            break;
        case 0x00FEULL:
            message << "エラー発報の検証を行いました。<BEGIN>　ABCDEFG$\"#%&(#='#！\\/～:]@＠■ 機種依存文字→{槩} <END>";
            break;
        default:
            message << "未定義エラー。";
            break;
        }

        (void)writeErrorLog(message.str(), "エラーログ", level);     // Go output error log.
        message << str_crlf << "ご迷惑をお掛けし申し訳ございません。";
        return message.str();
    }

}  // namespace exceptions