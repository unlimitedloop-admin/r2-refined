## Assignments

### <span style="color: salmon; ">Bug Report 1</span>
該当プロジェクトをx86環境でビルドした場合に以下の警告メッセージがビルドログに記録される。

>10\Include\10.0.22000.0\um\winnt.h(1010,5)' の式またはステートメントのため、'ULONGLONG Int64ShllMod32(ULONGLONG,DWORD)' の 'inline' 関数定義をモジュールに書き込めませんでした。
1>可能な場合は、こちらで再現を提供してください: https://developercommunity.visualstudio.com
1>C:\Program Files (x86)\Windows Kits\10\Include\10.0.22000.0\um\winnt.h(1021,1): message : 申し訳ございません: 認識できない 'C:\Program Files (x86)\Windows Kits\10\Include\10.0.22000.0\um\winnt.h(1026,5)' の式またはステートメントのため、'LONGLONG Int64ShraMod32(LONGLONG,DWORD)' の 'inline' 関数定義をモジュールに書き込めませんでした。
1>可能な場合は、こちらで再現を提供してください: https://developercommunity.visualstudio.com
1>C:\Program Files (x86)\Windows Kits\10\Include\10.0.22000.0\um\winnt.h(1037,1): message : 申し訳ございません: 認識できない 'C:\Program Files (x86)\Windows Kits\10\Include\10.0.22000.0\um\winnt.h(1042,5)' の式またはステートメントのため、'ULONGLONG Int64ShrlMod32(ULONGLONG,DWORD)' の 'inline' 関数定義をモジュールに書き込めませんでした。
1>可能な場合は、こちらで再現を提供してください: https://developercommunity.visualstudio.com

上記ログは全てx86環境でのみ発生し、x64プロセッサ向けビルドでは発生しない。  
この件で疑われるのはinline関数であり、ウェブ上のヒントによるとこの問題は"C++20 compliant"でのみ発生すると報告があった。
C++20に対応するVisual Studioの問題の可能性もある。


#### <span style="color: #3B7; ">解決策</span>

Visual Studioプロジェクトファイルのローカル情報をまとめたMSBuild形式のXMLファイル".vcxproj"の構造に問題が起きていた。  
ソースファイルとしてコンパイルされるべきグループにヘッダファイルが含まれており、このファイルにインライン関数を記述している事により発生していた可能性が高い。  
対処としては、一度この該当ヘッダファイルをプロジェクトから除外してリビルド、再びプロジェクトに参加させて再リビルドする事でこの".vcxproj"の構造の問題を解消する事ができた。  

この時点で上記の警告メッセージが出力される事はなくなった。
