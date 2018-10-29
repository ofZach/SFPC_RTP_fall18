#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "ctmf.h"
#include "ofxGui.h"
#include "ofxKinect.h"

using namespace milton;

#define USE_VIDEO

#ifdef USE_VIDEO
#define INPUT_W 512
#define INPUT_H 424
#else
#define INPUT_W 640
#define INPUT_H 480
#endif

class inputManager {
    
public:
    
    void setup();
    void update();
    void draw();
    
    void changeMovie( string fileName);
    
    
#ifdef USE_VIDEO
    ofVideoPlayer player;
#else
    ofxKinect kinect;
    ofTexture texDepth;
    ofTexture texRGB;
#endif
    
    
    
    // I basically have a contour that represents the blob on this frame.
    
    bool bFoundABlobThisFrame;
    unsigned char * thresholdedImage;
    
    unsigned char * graypixels;
    unsigned char * medianFiltered;
    
    ofImage medianFilteredResult;
    
    ofxCv::ContourFinder finder;
    
    ofParameterGroup group;
    ofParameter < int > threshold;
    ofParameter < int > medianFilterAmount;
    ofParameter < float > speed;
    ofxPanel panel;
    
    
};
