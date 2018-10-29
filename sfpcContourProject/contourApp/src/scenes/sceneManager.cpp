

#include "sceneManager.h"

//---------------------------------------------------------------
void sceneManager::setup(){
    
    // traditional for loop
    for (int i = 0; i < scenes.size(); i++){
        scenes[i]->setup();
    }
    
    // range based for loop
//    for (auto scene : scenes){
//        scene->setup();
//    }
//    
    currentScene = 0;
    
}

void sceneManager::nextScene(){
    currentScene++;
    currentScene %= scenes.size();
}



//---------------------------------------------------------------
void sceneManager::update(){
    scenes[currentScene]->update();
    
}


//---------------------------------------------------------------
void sceneManager::draw(){
    ofPushStyle();
    scenes[currentScene]->draw();
    ofPopStyle();
}