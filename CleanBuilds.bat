set PROJECTDIR=%WORKSPACE%
if ["%WORKSPACE%"]==[""] (
    set PROJECTDIR=%~dp0
)

set UE4ROOT="C:\Unreal\UE_4.23"
set PROJECT_NAME=RainbowRedux
set OUT_DIR=%PROJECTDIR%\Packaged
set BUILD_PROFILE=Development
cd %~dp0

RMDIR /s /q %OUT_DIR%
RMDIR /s /q %PROJECTDIR%\Saved
RMDIR /s /q %PROJECTDIR%\Intermediate
RMDIR /s /q %PROJECTDIR%\Plugins\UnrealEnginePython
RMDIR /s /q %PROJECTDIR%\Content\Scripts

del /f /q %PROJECTDIR%\Binaries\Win64\*.pdb
del /f /q %PROJECTDIR%\Binaries\Win64\*.dll
del /f /q %PROJECTDIR%\Binaries\Win64\*.exe
