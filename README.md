# RainbowRedux

RainbowRedux is an attempt to remake the engine for the original Rainbow Six games. This project is not a remake of the game, and does not distribute game content. You require the original game to play. You can pick up a copy from ebay or [GOG.com](https://www.gog.com/game/tom_clancys_rainbow_six)

This repository holds the Unreal Engine project.

## Discord / Community

If you'd like to discuss this project more and hear the latest info, please join us on <a href="https://discord.gg/WK9jbqR"><img src="https://img.shields.io/badge/discord-join-7289DA.svg?logo=discord&longCache=true&style=flat" /></a>.

## Setup / Prereqs

* Install Python 3.7 from [here](https://www.python.org/downloads/release/python-376/) (I recommend the 64 bit version)
  * Make sure to select custom install, and tick every option for "all users" so it installs to C:\Program Files\Python37
* Install git and git-lfs (These should install with SourceTree, GitKraken, or GitHub Desktop)
* Install Unreal Engine 4.23 through the Epic Games launcher.
* Clone this repository
* Run Setup.bat to clone the extra dependencies and copy files to the correct spot
* Double click the RainbowRedux.uproject file

## Project information

### Asset, coding and naming standards/conventions

* Python code should be Python 3.7 compatible, mostly adhering to the PEP8 standard
* Unreal assets and C++ code should mostly adhere to the following standards
  * [Unreal Coding Standards](https://docs.unrealengine.com/en-US/Programming/Development/CodingStandard/index.html)
  * [Allars' UE4 Style Guide](https://github.com/Allar/ue4-style-guide)

### Layout

This project uses 3 repositories together.

* RainbowRedux(This repository)
* [RainbowSixFileReaders (Python library containing the majority of data loading code)](https://github.com/RainbowRedux/RainbowSixFileConverters)
  * This is cloned in Content\Scripts
* [UnrealEnginePython (Unreal plugin providing python environment and binding)](https://github.com/boristsr/UnrealEnginePython)
  * This is cloned in Plugins\UnrealEnginePython

If you are interested in working on this project you will probably only ever need to look at the first 2 repos.

Due to the need for some developers to use their own forks of repositories I have not set these up as submodules, rather these can be cloned through the setup.bat step. Please change this file, or re-clone these repositories manually as appropriate. (Don't forget to copy PIL like in setup.bat)

## Unreal Engine Version

This project is currently based on Unreal Engine 4.23. The 2 main factors that will cause this project to lag behind the latest unreal version is:

* time involved in upgrading a project. It's not always a quick operation.
* Support from UnrealEnginePython. The last official support is for 4.23, with community maintained branches for 4.24.

I am planning to upgrade the project to 4.25 on release, provided there is support from a community branch of UnrealEnginePython, as this will give more stable ray tracing support.

## Git LFS notes

This project uses git lfs for binary files. This could get expensive over time so please try not to commit excessively large files.

* Do not submit any copyrighted files.
* Do not submit any files that are created from copyrighted files.
