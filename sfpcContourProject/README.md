# SFPC Fall 2016 Contours Project

### 1. Installing

In terminal navigate to your OpenFrameworks `of_v0.9.3_osx_release/apps` (not in `of_v0.9.3_osx_release/apps/myApps`)

run `git clone https://github.com/ofZach/sfpcContourProject.git`

### 2. Creating scenes

Navigate to the root directory of the project

run `./generateScene.sh YOUR_SCENE_NAME`

_Recommended_ to name your scene with the "name + Scene" convention, ie: `puppyScene`, `bubbleScene`

### 3. Adding scene to XCode project 

Drag and drop the scene into the XCode project 

*Important* check `Create groups` and in "Add to targets:" check `contourApp` 

