@echo off
cd %~dp0
call EnvVars.bat

set ZIP_LOC=%PROJECTDIR%\Packaged\RainbowRedux.zip
set SZ_LOC=%PROJECTDIR%\Packaged\RainbowRedux.7z
set SZ_DEBUG_LOC=%PROJECTDIR%\Packaged\RainbowRedux-debug.7z

::Delete old build artifacts
echo Deleting old build artifacts
del %ZIP_LOC%
del %SZ_LOC%
del %SZ_DEBUG_LOC%

echo Moving to an appropriate folder name
::Copy to a fresh folder so we don't ruin the original build and it's PDBs
move %OUT_DIR%\WindowsNoEditor %OUT_DIR%\RainbowRedux

echo Compressing build with PDBs
::Compress with PDBs
%SEVENZ_EXE% a %SZ_DEBUG_LOC% %OUT_DIR%\RainbowRedux

echo Removing PDB files
::Delete PDB that we don't want to distribute
del %OUT_DIR%\RainbowRedux\RainbowRedux\Binaries\Win64\RainbowRedux.pdb

echo Compressing build without PDBs
::Compress without PDBs
%SEVENZ_EXE% a %SZ_LOC% %OUT_DIR%\RainbowRedux
