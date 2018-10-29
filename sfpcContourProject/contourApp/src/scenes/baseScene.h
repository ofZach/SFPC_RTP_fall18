#pragma once

#include "ofMain.h"
#include "contourTracker.h"


class baseScene {
    
public:
    
    virtual void setup(){};
    virtual void update(){};
    virtual void draw(){};
    
    
    contourTracker * CT;
    
    // ->  (like . but for PO box)
    
    
    
};
