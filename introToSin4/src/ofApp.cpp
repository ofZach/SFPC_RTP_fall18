#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    
    ofBackground(0);
    
    // sin and cos are based on circle so it's easy
    // to get back to a circle
    
    float time = ofGetElapsedTimef();
    
    float xorig = 400;
    float yorig = 400;
    
    //float maxRadius = ofMap(sin(time*2.6), -1, 1, 100,300);
    
    float radius = ofMap(sin(time*40.5), -1, 1, 10, 200);
    float angle = ofGetElapsedTimef();

    ofPoint pt;
    
    // x = xorig + radius * cos(angle);
    // y = yorig + radius * sin(angle);
    
    pt.x = xorig + radius * cos(angle);
    pt.y = yorig + radius * sin(angle);
    
    line.addVertex(pt);
    
    if (line.size() > 100){
        line.getVertices().erase(line.getVertices().begin());
    }
    line.draw();
    ofDrawCircle(pt, 5);
    
    
    
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
