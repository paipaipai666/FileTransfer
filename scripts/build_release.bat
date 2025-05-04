@echo off
title qmake and nmake build prompt
set MINGW_PATH=d:\Qt\Tools\mingw810_64
set QT_DIR=d:\Qt\5.15.2\mingw81_64
set BUILD_DIR=%cd%\build
set PRO_DIR=%cd%
set PATH=%MINGW_PATH%\bin;%QT_DIR%\bin;%PATH%


if not exist %BUILD_DIR% (
    md %BUILD_DIR%
)

cd build
qmake.exe %PRO_DIR%\FileTransfer.pro -spec win32-g++ "CONFIG+=release"
if exist %BUILD_DIR%\release\FileTransfer.exe del %BUILD_DIR%\release\FileTransfer.exe
@REM d:\Qt\Tools\QtCreator\bin\jom.exe -j4
%MINGW_PATH%\bin\mingw32-make -f Makefile.Release
cd release
if not exist %BUILD_DIR%\release\Qt5Core.dll (
    windeployqt FileTransfer.exe
)