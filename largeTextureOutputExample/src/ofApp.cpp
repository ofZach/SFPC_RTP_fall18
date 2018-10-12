#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    
    // assume our target is 8.5x11 -- we can caluate the w/h of the largest
    // texture at that aspect ratio
    
    int value;
    glGetIntegerv(GL_MAX_TEXTURE_SIZE, &value);   //Returns 1 value
    float total = 11 + 8.5;
    w = (8.5 / total) * (value-1);
    h = (11.0 / total) * (value-1);
    largeOffscreenImage.allocate(w, h, GL_RGBA);
    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    
    
    largeOffscreenImage.begin();
    
    ofClear(255,255,255,255);
    ofSetColor(0,0,0);
    ofLine(0,0,w, h);
    for (int i = 0; i < 100; i++){
        ofSetColor(ofRandom(0,255));
        ofRect(ofRandom(0,w), ofRandom(0,h), w/5, h/2);
    }
    largeOffscreenImage.end();
    
    ofRectangle bounds(0,0, ofGetWidth(), ofGetHeight());
    ofRectangle target(0,0,w,h);
    target.scaleTo(bounds);
    
    largeOffscreenImage.draw(target);
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if (key == ' '){
   
        ofPixels p;
        largeOffscreenImage.readToPixels(p);
        ofSaveImage(p, ofGetTimestampString() + ".png");
        
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
