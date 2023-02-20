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
//      Last update     : 2023/02/20
//
//      File version    : 4
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
// PROJECT USING HEADER
#include "src/traceable/logclass.h"



/* SOURCES */
namespace exceptions {

    /* using namespace */
    using namespace traceable;



    std::string ErrorList0x00x::Minor(unsigned __int64 error_code, LogClass level) {
        std::ostringstream message;
        const std::string str_crlf = "\r\n";

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
        case 0x0005ULL:
            message << "SetDrawScreen(DX_SCREEN_BACK)関数が失敗しました。";
            break;
        case 0x0006ULL:
            message << "SetDrawScreen(DX_SCREEN_FRONT)関数が失敗しました。";
            break;
        case 0x0007ULL:
            message << "SetOutApplicationLogValidFlag(FALSE)関数が失敗しました。";
            break;
        case 0x0008ULL:
            message << "SetApplicationLogSaveDirectory関数が失敗しました。";
            break;
        case 0x0009ULL:
            message << "SetAlwaysRunFlag(TRUE)関数が失敗しました。";
            break;
        case 0x000AULL:
            message << "SetAlwaysRunFlag(FALSE)関数が失敗しました。";
            break;
        case 0x000BULL:
            message << "ChangeWindowMode(FALSE)関数が失敗しました。";
            break;
        case 0x000CULL:
            message << "SetUseMenuFlag(FALSE)関数が失敗しました。";
            break;
        case 0x000DULL:
            message << "ChangeWindowMode(TRUE)関数が失敗しました。";
            break;
        case 0x000EULL:
            message << "SetWindowPosition(X, Y)関数が失敗しました。";
            break;
        case 0x000FULL:
            message << "SetWindowSizeExtendRate(N)関数が失敗しました。";
            break;
        case 0x0011ULL:
            message << "不明なアクティベータキーです。";
            break;
        case 0x0012ULL:
            message << "SetGraphMode関数が失敗しました。";
            break;
        case 0x0013ULL:
            message << "SetWindowText関数が失敗しました。";
            break;
        case 0x0014ULL:
            message << "SetDoubleStartValidFlag(FALSE)関数が失敗しました。";
            break;
        case 0x0015ULL:
            message << "DxLib_Init関数が失敗しました。";
            break;
        case 0x0016ULL:
            message << "プログラム終了時にDxLib_Endをコールする登録処理ができませんでした。";
            break;
        case 0x0017ULL:
            message << "DxLib_End関数が失敗しました。";
            break;
        case 0x0018ULL:
            message << "SetUseKeyAccelFlag(TRUE)関数が失敗しました。";
            break;
        case 0x0019ULL:
            message << "AddKeyAccel_ID関数が失敗しました。ID_40001の登録。";
            break;
        case 0x001AULL:
            message << "LoadMenuResource(IDR_MENU1)関数が失敗しました。";
            break;
        case 0x001BULL:
            message << "SetUseMenuFlag(TRUE)関数が失敗しました。";
            break;
        case 0x001CULL:
            message << "ウィンドウの属性変更に失敗しました。";
            break;
        default:
            message << "未定義エラー。";
            break;
        }

        return message.str();
    }

}  // namespace exceptions