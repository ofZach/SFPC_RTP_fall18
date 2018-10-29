#!/bin/bash
CYAN='\033[0;36m'
RED='\033[0;31m'
NC='\033[0m'

if [ $# -eq 1 ]
then
    SCENE_NAME="$1"
    cp -r contourApp/src/scenes/emptyScene "$SCENE_NAME"
    sed "s/emptyScene/$SCENE_NAME/g" contourApp/src/scenes/emptyScene/emptyScene.h > "$SCENE_NAME/$SCENE_NAME.h"
    sed "s/emptyScene/$SCENE_NAME/g" contourApp/src/scenes/emptyScene/emptyScene.cpp > "$SCENE_NAME/$SCENE_NAME.cpp"
    rm $SCENE_NAME/emptyScene.cpp
    rm $SCENE_NAME/emptyScene.h
    mv $SCENE_NAME contourApp/src/scenes/
    open contourApp/src/scenes/$SCENE_NAME
    echo -e "${CYAN}SUCCESS!${NC}\nCreated folder: $SCENE_NAME\nYou can drag the folder into your project"
else
    echo -e "${RED}ERROR${NC}\nInstructions: './generate_scene.sh NEW_SCENE_NAME'"
fi
