#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    
    
    
    //cout << ofGetElapsedTimef() << " " << sin(ofGetElapsedTimef()) << endl;
    
    float sinOfTime = sin(ofGetElapsedTimef());
    float sinOfTimeRemmapped = ofMap(sinOfTime, -1, 1, 0, 255);
    ofSetColor(sinOfTimeRemmapped);
    ofDrawCircle(300,300, 100);
    
    float sinOfTime2 = sin(ofGetElapsedTimef()+TWO_PI*0.33);
    float sinOfTimeRemmapped2 = ofMap(sinOfTime2, -1, 1, 0, 255);
    ofSetColor(sinOfTimeRemmapped2);
    ofDrawCircle(500,300, 100);
    
    float sinOfTime3 = sin(ofGetElapsedTimef()+TWO_PI*0.66);
    float sinOfTimeRemmapped3 = ofMap(sinOfTime3, -1, 1, 0, 255);
    ofSetColor(sinOfTimeRemmapped3);
    ofDrawCircle(700,300, 100);
    
    
    
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
