# Follow these steps in preparation for release.

1. Write release notes
2. Build with build.bat
3. Put release notes in game root DIR
4. Ensure PNG cache is disabled in the python code in the release build
    1. Stored in: Content/Scripts/UnrealImporters/ImporterSettings.py
5. Package with package.bat