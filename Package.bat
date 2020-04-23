set OUT_DIR=.\Packaged
set ZIP_LOC=.\Packaged\RainbowRedux.zip
set SZ_LOC=.\Packaged\RainbowRedux.7z
set SEVENZ_EXE="C:\Program Files\7-Zip\7z.exe"

::Copy to a fresh folder so we don't ruin the original build and it's PDBs
RMDIR /s /q %OUT_DIR%\RainbowRedux\
xcopy /s %OUT_DIR%\WindowsNoEditor %OUT_DIR%\RainbowRedux\

::Delete PDB that we don't want to distribute
del %OUT_DIR%\RainbowRedux\RainbowRedux\Binaries\Win64\RainbowRedux.pdb

::Delete old build artifacts
del %ZIP_LOC%
del %SZ_LOC%

::Compress build into 2 formats
powershell Compress-Archive %OUT_DIR%\RainbowRedux %ZIP_LOC%
%SEVENZ_EXE% a %SZ_LOC% %OUT_DIR%\RainbowRedux
pause