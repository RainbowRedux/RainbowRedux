# RainbowRedux v0.1 - First Release - "Level Explorer"

RainbowRedux is an attempt to remake the engine for the original Rainbow Six games.

This project is not a remake of the game, and does not distribute game content. You require the original game to play. You can pick up a copy from ebay or [GOG.com](https://www.gog.com/game/tom_clancys_rainbow_six). A demo is available on [archive.org](https://archive.org/details/TomClancysRainbowSixDemo).

## Release History

* **0.1** - First Release - "Level Explorer"

## Instructions

Upon launching the game you will be prompted to locate your RainbowSix.exe file. Navigate to where your original RainbowSix installation is and select this executable.

### Choosing a map

To see a list of available missions bring down the console by pressing the tilde key (~) twice and then use the command "ce ListMissions" to see the available missions. To load a mission, type "ce LoadMission MISSION-NAME". Keep in mind the mission name is case sensitive.

### Speeding up loading with PNG Cache

The longest part of loading currently is processing the RSBs. Since this is all done in python it's relatively slow. The code can save PNGs beside the RSBs for quicker loading the next time. If you'd like to use this functionality you can enable it in python. It's disabled by default so no changes are made to your original installation.

## Controls

* WASD + Mouse - Standard movement controls
* Space to jump
* N - Toggle Night Vision
* R - Reset Player position
* V - Toggle Room volume visibility
* P - Toggle Portal visibility

### Debug weapon

* Left mouse button fires hit traces.
  * Red means hit
  * Yellow means hit a surface that bullets will penetrate
  * Blue means miss
* Right mouse button fires a test grenade projectile

### Debug Controls

#### Viewmodes

* CTRL+F1 = Wireframe
* CTRL+F2 = Unlit
* CTRL+F3 = Normal
* CTRL+F4 = Detailing Lighting
* CTRL+F5 = Shader Complexity

#### Console commands

Press ` (tilde) twice to bring down the console

* ce ListMissions
* ce LoadMission
* ce ResetPlayer

**Disable fog** by typing "ce ToggleFog"

**Change ambient light brightness** by typing "ce SetAmbientBrightness \<value\>" where value can be a floating point number. I recommend keeping the value between 0 and 5.

**FPS** can be viewed by typing "stat fps"

**Draw Calls** can be viewed by typing "stat rhi" and looking for "DrawPrimitive Calls" in the on screen display

## Known Issues

* **Fixed map start** - Map starting locations are specified in mission files which are not processed yet. In the mean time it's possible that you will spawn in a map and be stuck. You can reset your character with by pressing R
* **Doors and dynamic objects are all in a single spot** - Dynamic objects aren't yet processed, and by default the files store the geometry for all at 0,0,0.
* **Masked materials have missing pixels or aren't masked out** - The masked materials color key support is still being worked on. The tricky part is replicating exact behaviour of color matching from a full 24bpp color mask value with a 16bit image. The color precision is different so it's not a perfect match. I still have a few ideas on how to improve this.
* **Some masked materials have a strange bright edge** - Things like the fire in M02 suffers from a texture repeat and UV mapping that provides no tolerance. This never showed up in the original game because even though the colors were bilinear filtered but the masking was performed with nearest filtering.
* **Light leaking through walls/rooms** - Lights currently leak through some walls. Without making every light a shadow caster this will be difficult to fully resolve. I expect as light value mapping is refined some values such as the radius lights will be altered which may improve this. Also once portals are used for toggling rooms on and off, this should also improve the situation.
* **Incorrect lighting** - Lighting cannot be perfectly matched with the old game since lighting is now handled very differently. Having said that, lighting will improve significantly over time as properties are interpretted more accurately. In later releases some maps might have lighting setups done by hand in Unreal and the original lighting disabled.
* **Incorrect Fog** - Fog is another value that is stored in mission files, and is meant to only be rendered in certain rooms. At the moment the fog is roughly mapped from the mission file, but should improve with time. There is going to be a balance between replicating the look of the original game, visual quality improvement, and gameplay that will need to happen later in the project.
* **Incorrect Ambient Lighting** - Ambient lighting is also stored in mission files. This will improve with time
* **Large packaged project size** - This is an early stage unreal project which I have mostly built off the First Person template. In the future I will be spending some time to bring the size down significantly by stripping out unused assets and plugins.
* **Wrong Skies/Dynamic skies not used** - Currently unless a map has a static sky, a default unreal sky is visible. This will be fixed at some point in the future.
* **obstacletest.map from Rainbow Six doesn't load** - Best as I can tell this map was a very early feature testing map that was shipped by accident. It's only got some of the expected data structures and deviates from the standard file format. I haven't invested the time to get this map loading. Support for this map is not planned.
* **Some collision is wrong** - This is still being worked through. The original game used a hybrid 2D/3D collision system. Rogue spear appeared to use a similar system, but had very different data structures for storing this data. Some data is still not read (like surface properties from STP files). At the moment I'm trying to coerce it all to work in 3D, but at some point I'll likely need to generate a 3D mesh based off the 2d collision flags. On top of that, currently the debug gun shoots projectiles configured like grenades, so walls or objects that would allow grenades to pass through can't be hit, while walls that would allow bullets to travel through can be hit.

## Credits and attributions

Philip Edwards - Python libraries and Rainbow Redux unreal project.

Alex Kimov - Significant contributor to deciphering the file formats.
A version of Python is included. This is subject to the [Python Software License](https://opensource.org/licenses/PythonSoftFoundation.php).

Pillow is used for supporting image functions.  This is subject to the [PIL Software License](https://github.com/python-pillow/Pillow/blob/master/LICENSE)

UnrealEnginePython is used for enabling python at runtime.

Unreal Engine 4 is used for the game engine. 

### Special Thanks

Redstorm Entertainment for the fantastic games.
