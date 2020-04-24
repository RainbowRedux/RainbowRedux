@echo off
echo Before running this script, please ensure you meet the following requirements before continuing:
echo - Python 3.7 installed in C:\Program Files\Python37
echo - git is installed
echo If you have unsaved work in Content\Scripts it will be deleted

if ["%~1"]==["/force"] (
    echo "Force paramater supplied, skipping approval"
    goto START
)

echo .
echo Press CTRL-C, or close this window to abort
pause

:START
@echo on

rmdir /s /q Content\Scripts\
mkdir Content\Scripts\
git clone https://github.com/RainbowRedux/RainbowSixFileConverters Content\Scripts
mkdir Plugins
git clone https://github.com/boristsr/UnrealEnginePython Plugins\UnrealEnginePython

xcopy /s Redist\PIL Content\Scripts\PIL\ /EXCLUDE:XCopyExclude.txt
