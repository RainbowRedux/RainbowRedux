set UE4ROOT="E:\Epic Games\UE_4.23"
set PROJECT_NAME=RainbowRedux
set PROJECTDIR=%~dp0
set OUT_DIR=.\Packaged
set BUILD_PROFILE=Development
cd %~dp0

RMDIR /s /q %OUT_DIR%
MKDIR %OUT_DIR%

::Run UE4 packaging process
call %UE4ROOT%\Engine\Build\BatchFiles\RunUAT.bat BuildCookRun -project=%PROJECTDIR%\%PROJECT_NAME%.uproject -clientconfig=%BUILD_PROFILE% -platform=Win64 -cook -maps=AllMaps -build -compile -stage -pak -archive -UnVersioned -archivedirectory="%OUT_DIR%"
::Copy Python scripts
mkdir %OUT_DIR%\WindowsNoEditor\%PROJECT_NAME%\Content\Scripts
xcopy /s %PROJECTDIR%\Content\Scripts %OUT_DIR%\WindowsNoEditor\%PROJECT_NAME%\Content\Scripts\ /EXCLUDE:XCopyExclude.txt
::Copy Pillow
xcopy /s %PROJECTDIR%\Redist\PIL %OUT_DIR%\WindowsNoEditor\%PROJECT_NAME%\%PROJECT_NAME%\Content\Scripts\PIL\ /EXCLUDE:XCopyExclude.txt
::Copy TKinter
xcopy /s %PROJECTDIR%\Redist\tkinter %OUT_DIR%\WindowsNoEditor\%PROJECT_NAME%\%PROJECT_NAME%\Content\Scripts\tkinter\ /EXCLUDE:XCopyExclude.txt
::Copy Python
xcopy /s %PROJECTDIR%\Redist\Python\* %OUT_DIR%\WindowsNoEditor\%PROJECT_NAME%\Binaries\Win64\ /EXCLUDE:XCopyExclude.txt

pause