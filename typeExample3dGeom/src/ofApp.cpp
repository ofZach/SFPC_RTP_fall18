#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    font.load("helvetica.otf", 100, true, true, true);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(0);
    
    ofEnableDepthTest();
    
    //ofEnableBlendMode(OF_BLENDMODE_ADD);
    
    //cam.enableOrtho();
    
    cam.begin();
    ofSetColor(255);
    
    font.drawStringAsShapes("muriel cooper",0,0);
    
    //drawString("muriel cooper",0,0);
    //ofDrawRectangle(0,0,100,100);
    
    ofPushMatrix();
    ofRotateY(90);
    ofSetColor(255,0,0);
    font.drawStringAsShapes("muriel cooper",0,0);
    //ofDrawRectangle(0,0,100,100);
    ofPopMatrix();
    
    cam.end();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
