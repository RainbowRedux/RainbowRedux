@echo off
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
MKDIR %OUT_DIR%

::Run UE4 packaging process
echo UE4 Build process starting
call %UE4ROOT%\Engine\Build\BatchFiles\RunUAT.bat BuildCookRun -project=%PROJECTDIR%\%PROJECT_NAME%.uproject -clientconfig=%BUILD_PROFILE% -platform=Win64 -cook -maps=AllMaps -build -compile -stage -pak -archive -UnVersioned -archivedirectory="%OUT_DIR%"
IF %ERRORLEVEL% NEQ 0 (
    exit /b %ERRORLEVEL%
)

::Copy Python scripts
echo Copying python libraries
mkdir %OUT_DIR%\WindowsNoEditor\%PROJECT_NAME%\Content\Scripts
xcopy /s %PROJECTDIR%\Content\Scripts %OUT_DIR%\WindowsNoEditor\%PROJECT_NAME%\Content\Scripts\ /EXCLUDE:XCopyExclude.txt
::Copy Pillow
xcopy /s %PROJECTDIR%\Redist\PIL %OUT_DIR%\WindowsNoEditor\%PROJECT_NAME%\%PROJECT_NAME%\Content\Scripts\PIL\ /EXCLUDE:XCopyExclude.txt
::Copy TKinter
xcopy /s %PROJECTDIR%\Redist\tkinter %OUT_DIR%\WindowsNoEditor\%PROJECT_NAME%\%PROJECT_NAME%\Content\Scripts\tkinter\ /EXCLUDE:XCopyExclude.txt
::Copy Python
xcopy /s %PROJECTDIR%\Redist\Python\* %OUT_DIR%\WindowsNoEditor\%PROJECT_NAME%\Binaries\Win64\ /EXCLUDE:XCopyExclude.txt

::Write build number
echo Writing Version Information
echo %PROJECT_NAME% Version Information > %OUT_DIR%\WindowsNoEditor\Version.txt
echo Jenkins project: %JOB_NAME% >> %OUT_DIR%\WindowsNoEditor\Version.txt
echo Jenkins build: %BUILD_NUMBER% >> %OUT_DIR%\WindowsNoEditor\Version.txt
echo Jenkins node: %NODE_NAME% >> %OUT_DIR%\WindowsNoEditor\Version.txt
echo GIT URL: %GIT_URL% >> %OUT_DIR%\WindowsNoEditor\Version.txt
echo GIT Branch: %GIT_BRANCH% >> %OUT_DIR%\WindowsNoEditor\Version.txt
echo GIT Commit: %GIT_COMMIT% >> %OUT_DIR%\WindowsNoEditor\Version.txt

::Copy release notes
echo Copying Release Notes
copy "%PROJECTDIR%\Documentation\Release Notes\ReleaseNotes-Latest.md" %OUT_DIR%\WindowsNoEditor\ReleaseNotes.txt
