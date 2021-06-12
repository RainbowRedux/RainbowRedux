@echo off
cd %~dp0
call EnvVars.bat

echo Removing dirty directories
RMDIR /s /q %OUT_DIR%
RMDIR /s /q %PROJECTDIR%\Saved
RMDIR /s /q %PROJECTDIR%\Intermediate
RMDIR /s /q %PROJECTDIR%\Plugins\UnrealEnginePython
RMDIR /s /q %PROJECTDIR%\Content\Scripts

echo Remove prebuilt binaries
del /f /q %PROJECTDIR%\Binaries\Win64\*.pdb
del /f /q %PROJECTDIR%\Binaries\Win64\*.dll
del /f /q %PROJECTDIR%\Binaries\Win64\*.exe

exit /b 0
