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
//      Last update     : 2023/04/08
//
//      File version    : 6
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



    std::wstring ErrorListOverlapped::Major(unsigned __int64 error_code, LogClass level) {
        std::wostringstream message;
        const std::wstring str_crlf = L"\r\n";
        message << L"発生したエラーコードは：[" << L"0x" << std::setw(6) << std::hex << std::uppercase << std::setfill(L'0') << error_code << L"] です。";
        (void)writeErrorLog(message.str(), L"エラーコード");
        message.str(L""); message.clear();

        // This switch statement includes some commonly-defined error codes.
        switch (error_code & 0x00FF00ULL) {
        case 0x00E000ULL:
            message << L"GetHitKeyStateAll関数が失敗しました。";
            break;
        case 0x00E100ULL:
            message << L"キー配列番号が異常値を示しました。詳細は以下を参照して下さい。";
            break;
        case 0x00E200ULL:
            message << L"[SpriteLoader] メモリ上のグラフィックの削除処理が失敗しました。";
            break;
        case 0x00E300ULL:
            message << L"[SpriteLoader] グラフィックデータのメモリへの展開ができませんでした。";
            break;
        case 0x00E400ULL:
            message << L"[SpriteLoader] グラフィックデータの描画処理が失敗しました。";
            break;
        case 0x00E500ULL:
            message << L"[MapstructLoader] バイナリデータのオープンに失敗しました。";
            break;
        case 0x00E600ULL:
            message << L"[TileLoader] メモリ上のグラフィックの削除処理が失敗しました。";
            break;
        case 0x00E700ULL:
            message << L"[TileLoader] グラフィックデータのメモリへの展開ができませんでした。";
            break;
        case 0x00E800ULL:
            message << L"[TileLoader] グラフィックデータの描画処理が失敗しました。";
            break;
        case 0x00E900ULL:
            message << L"[AudioLoader] 不正な引数です。";
            break;
        case 0x00EA00ULL:
            message << L"[AudioLoader] メモリ上のサウンドデータハンドルの削除処理が失敗しました。";
            break;
        case 0x00EB00ULL:
            message << L"[AudioLoader] サウンドデータハンドルの作成が失敗しました。";
            break;
        case 0x00FE00ULL:
            message << L"エラー発報の検証を行いました。<BEGIN>　ABCDEFG$\"#%&(#='#！\\/～:]@＠■ 機種依存文字→{槩} <END>";
            break;
        default:
            message << this->Minor(error_code, level);
            break;
        }

        (void)writeErrorLog(message.str(), L"エラーログ", level);     // Go output error log.
        message << str_crlf << L"ご迷惑をお掛けし申し訳ございません。";
        return message.str();
    }

}  // namespace exceptions
