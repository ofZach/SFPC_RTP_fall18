#pragma once

#include "ofMain.h"
#include "baseScene.h"

class tomoya : public baseScene{
    
public:
    
    void setup();
    void update();
    void draw();
    float* data;
    
    ofVec2f currentpt[100], pastpt[100];
    ofPolyline currentframe, pastframe;
    ofFbo main;
    ofFbo datafbo;
    ofShader datashader,shader;
    ofShader blurx;
    ofShader blury;
};
