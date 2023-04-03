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
//      Last update     : 2023/04/03
//
//      File version    : 6
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



    std::wstring ErrorList0x00x::Minor(unsigned __int64 error_code, LogClass level) {
        std::wostringstream message;
        const std::wstring str_crlf = L"\r\n";

        switch (error_code / 0x000100ULL) {
        case 0x0001ULL:
            message << L"環境変数取得処理で不明なエラーが発生したため、アプリケーションの実行は中断されます。";
            break;
        case 0x0002ULL:
            message << L"インストールされているオペレーティング・システムの不明なプロセッサ・アーキテクチャが返却されました。";
            break;
        case 0x0003ULL:
            message << L"Windows 7以前のOSは動作対象外です。";
            break;
        case 0x0004ULL:
            message << L"メモリ領域に十分な空き領域がないためアプリケーションは開始されません。";
            break;
        case 0x0005ULL:
            message << L"SetDrawScreen(DX_SCREEN_BACK)関数が失敗しました。";
            break;
        case 0x0006ULL:
            message << L"SetDrawScreen(DX_SCREEN_FRONT)関数が失敗しました。";
            break;
        case 0x0007ULL:
            message << L"SetOutApplicationLogValidFlag(FALSE)関数が失敗しました。";
            break;
        case 0x0008ULL:
            message << L"SetApplicationLogSaveDirectory関数が失敗しました。";
            break;
        case 0x0009ULL:
            message << L"SetAlwaysRunFlag(TRUE)関数が失敗しました。";
            break;
        case 0x000AULL:
            message << L"SetAlwaysRunFlag(FALSE)関数が失敗しました。";
            break;
        case 0x000BULL:
            message << L"ChangeWindowMode(FALSE)関数が失敗しました。";
            break;
        case 0x000CULL:
            message << L"SetUseMenuFlag(FALSE)関数が失敗しました。";
            break;
        case 0x000DULL:
            message << L"ChangeWindowMode(TRUE)関数が失敗しました。";
            break;
        case 0x000EULL:
            message << L"SetWindowPosition(X, Y)関数が失敗しました。";
            break;
        case 0x000FULL:
            message << L"SetWindowSizeExtendRate(N)関数が失敗しました。";
            break;
        case 0x0011ULL:
            message << L"不明なアクティベータキーです。";
            break;
        case 0x0012ULL:
            message << L"SetGraphMode関数が失敗しました。";
            break;
        case 0x0013ULL:
            message << L"SetWindowText関数が失敗しました。";
            break;
        case 0x0014ULL:
            message << L"SetDoubleStartValidFlag(FALSE)関数が失敗しました。";
            break;
        case 0x0015ULL:
            message << L"DxLib_Init関数が失敗しました。";
            break;
        case 0x0016ULL:
            message << L"プログラム終了時にDxLib_Endをコールする登録処理ができませんでした。";
            break;
        case 0x0017ULL:
            message << L"DxLib_End関数が失敗しました。";
            break;
        case 0x0018ULL:
            message << L"SetUseKeyAccelFlag(TRUE)関数が失敗しました。";
            break;
        case 0x0019ULL:
            message << L"AddKeyAccel_ID関数が失敗しました。ID_40001の登録。";
            break;
        case 0x001AULL:
            message << L"LoadMenuResource(IDR_MENU1)関数が失敗しました。";
            break;
        case 0x001BULL:
            message << L"SetUseMenuFlag(TRUE)関数が失敗しました。";
            break;
        case 0x001CULL:
            message << L"ウィンドウの属性変更に失敗しました。";
            break;
        case 0x001DULL:
            message << L"キーバインド処理が失敗しました。";
            break;
        case 0x001EULL:
            message << L"ジョイパッド／キーボード情報の更新に失敗しました。";
            break;
        default:
            message << L"未定義エラー。";
            break;
        }

        return message.str();
    }

}  // namespace exceptions