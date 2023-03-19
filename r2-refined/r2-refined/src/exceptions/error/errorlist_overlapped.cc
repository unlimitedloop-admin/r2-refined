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
//      File name       : errorlist_overlapped.cc
//
//      Author          : u7
//
//      Last update     : 2023/03/19
//
//      File version    : 3
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * The control of exception processing that is commonly reported.
**/



/* INCLUDES */
// PRIMARY HEADER
#include "errorlist_overlapped.h"
// C++ SYSTEM HEADER
#include <string>
#include <sstream>
#include <iomanip>
// PROJECT USING HEADER
#include "src/traceable/logclass.h"
#include "src/traceable/output_logs.h"



/* SOURCES */
namespace exceptions {

    /* using namespace */
    using namespace traceable;



    std::string ErrorListOverlapped::Major(unsigned __int64 error_code, LogClass level) {
        std::ostringstream message;
        const std::string str_crlf = "\r\n";
        message << "発生したエラーコードは：[" << "0x" << std::setw(6) << std::hex << std::uppercase << std::setfill('0') << error_code << "] です。";
        (void)writeErrorLog(message.str(), "エラーコード");
        message.str(""); message.clear();

        // This switch statement includes some commonly-defined error codes.
        switch (error_code & 0x00FF00ULL) {
        case 0x00E000ULL:
            message << "GetHitKeyStateAll関数が失敗しました。";
            break;
        case 0x00E100ULL:
            message << "キー配列番号が異常値を示しました。詳細は以下を参照して下さい。";
            break;
        case 0x00E200ULL:
            message << "[SpriteLoader] メモリ上のグラフィックの削除処理が失敗しました。";
            break;
        case 0x00E300ULL:
            message << "[SpriteLoader] グラフィックデータのメモリへの展開ができませんでした。";
            break;
        case 0x00E400ULL:
            message << "[SpriteLoader] グラフィックデータの描画処理が失敗しました。";
            break;
        case 0x00E500ULL:
            message << "[MapstructLoader] バイナリデータのオープンに失敗しました。";
            break;
        case 0x00E600ULL:
            message << "[TileLoader] メモリ上のグラフィックの削除処理が失敗しました。";
            break;
        case 0x00E700ULL:
            message << "[TileLoader] グラフィックデータのメモリへの展開ができませんでした。";
            break;
        case 0x00E800ULL:
            message << "[TileLoader] グラフィックデータの描画処理が失敗しました。";
            break;
        case 0x00FE00ULL:
            message << "エラー発報の検証を行いました。<BEGIN>　ABCDEFG$\"#%&(#='#！\\/～:]@＠■ 機種依存文字→{槩} <END>";
            // UNRESOLVED : It seems that character arrays that are only accepted in UTF-8 codepages can no longer be sent to ostringstream. (C++20)
            //message << u8"エラー発報の検証を行いました。<BEGIN>　ABCDEFG$\"#%&(#='#！\\/～:]@＠■ 機種依存文字→{槩} <END>";  // damn :(
            break;
        default:
            message << this->Minor(error_code, level);
            break;
        }

        (void)writeErrorLog(message.str(), "エラーログ", level);     // Go output error log.
        message << str_crlf << "ご迷惑をお掛けし申し訳ございません。";
        return message.str();
    }

}  // namespace exceptions
