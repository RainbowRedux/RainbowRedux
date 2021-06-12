set PROJECTDIR=%WORKSPACE%
if ["%WORKSPACE%"]==[""] (
    set PROJECTDIR=%~dp0
)

set UE4ROOT="S:\Engines\UE_4.23"
set PROJECT_NAME=RainbowRedux
set OUT_DIR=%PROJECTDIR%\Packaged
set BUILD_PROFILE=Development

set PROJECTDIR=%WORKSPACE%
if ["%WORKSPACE%"]==[""] (
    set PROJECTDIR=%~dp0
)

set SEVENZ_EXE="C:\Program Files\7-Zip\7z.exe"