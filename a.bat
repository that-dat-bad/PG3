@echo off
setlocal enabledelayedexpansion

echo ===============================
echo _ → - 一括変換（sln対応）
echo ===============================

REM ===== slnファイル名（必要なら変更）=====
set SLN=PG3.sln

REM --- フォルダ名を変更 ---
for /d %%D in (*_*) do (
    set "old=%%D"
    set "new=%%D"
    set "new=!new:_=-!"
    if not "!old!"=="!new!" (
        echo フォルダ: !old! → !new!
        ren "%%D" "!new!"
    )
)

REM --- 各フォルダ内のファイル名を変更 ---
for /d %%D in (*-*) do (
    pushd "%%D"
    for %%F in (*_*) do (
        set "old=%%F"
        set "new=%%F"
        set "new=!new:_=-!"
        if not "!old!"=="!new!" (
            echo  ファイル: !old! → !new!
            ren "%%F" "!new!"
        )
    )
    popd
)

REM --- sln の中身を書き換え ---
if exist "%SLN%" (
    echo sln を更新中...
    powershell -Command ^
        "(Get-Content '%SLN%') -replace '_','-' | Set-Content '%SLN%'"
) else (
    echo sln が見つかりません: %SLN%
)

echo ===============================
echo 完了しました
echo ===============================
pause
