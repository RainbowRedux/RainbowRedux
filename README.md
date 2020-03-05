# RainbowRedux

RainbowRedux is an attempt to remake the engine for the original Rainbow Six games. This project is not a remake of the game, and does not distribute game content. You require the original game to play. You can pick up a copy from ebay or [GOG.com](https://www.gog.com/game/tom_clancys_rainbow_six)

This repository holds the Unreal Engine project.

## Discord / Community

If you'd like to discuss this project more and hear the latest info, please join us on [Discord over here](https://discord.gg/YygR4S8).

## Setup / Prereqs

* Install Python 3.7 from [here](https://www.python.org/downloads/release/python-376/) (I recommend the 64 bit version)
  * Make sure to select custom install, and tick every option for "all users" so it installs to C:\Program Files\Python37
* Install git and git-lfs (These should install with SourceTree, GitKraken, or GitHub Desktop)
* Install Unreal Engine 4.23 through the Epic Games launcher.
* Clone this repository
* Run Setup.bat to clone the extra dependencies and copy files to the correct spot
* Double click the RainbowRedux.uproject file

## Project Layout

This project uses 3 repositories.

* RainbowRedux(This repository)
* [RainbowSixFileReaders (Python library containing the majority of data loading code)](https://github.com/RainbowRedux/RainbowSixFileConverters)
* [UnrealEnginePython (Unreal plugin providing python environment and binding)](https://github.com/boristsr/UnrealEnginePython)

If you are interested in working on this project you will probably only ever need to look at the first 2 repos.

## Unreal Engine Version

This project is currently based on Unreal Engine 4.23. The 2 main factors that will cause this project to lag behind the latest unreal version is:

* time involved in upgrading a project. It's not always a quick operation.
* Support from UnrealEnginePython. The last official support is for 4.23, with community maintained branches for 4.24.

I am planning to upgrade the project to 4.25 on release, provided there is support from a community branch of UnrealEnginePython, as this will give more stable ray tracing support.

## Git LFS notes

This project uses git lfs for binary files. This could get expensive over time so please try not to commit excessively large files.

* Do not submit any copyrighted files.
* Do not submit any files that are created from copyrighted files.
