@echo off
echo Before running this script, please ensure you meet the following requirements before continuing:
echo - Python 3.7 installed in C:\Program Files\Python37
echo - git is installed

pause

@echo on

mkdir Content\Scripts\
git clone https://github.com/RainbowRedux/RainbowSixFileConverters Content\Scripts
mkdir Plugins
git clone https://github.com/boristsr/UnrealEnginePython Plugins\UnrealEnginePython

xcopy /s Redist\PIL Content\Scripts\PIL\ /EXCLUDE:XCopyExclude.txt