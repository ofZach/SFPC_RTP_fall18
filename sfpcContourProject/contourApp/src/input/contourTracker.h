#pragma once

#include "ofMain.h"

class contourTracker {
    
public:
    
    void setup();
    void analyze( ofPolyline & curFrame );
    void draw();
    
    
    ofPolyline prevFrame;
    ofPolyline resampleSmoothed;
    
    
};