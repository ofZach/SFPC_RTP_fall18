#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    
    panel.setup();
    group.add(freq.set("freq", 0.1, 0.01, 0.3));
    group.add(yScale.set("yScale", 5, 0, 20));
    group.add(xScale.set("xScale", 5, 0, 20));
    panel.add(group);
    
    panel.loadFromFile("settings.xml");
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
 
    ofBackground(0);
    for (int i = 0; i < 100; i++){
        for (int j =0; j < 100; j++){
            ofDrawRectangle (i*10, j*10, xScale + xScale * sin(i*freq),yScale);
        }
    }
    
    
    if (bShowGui) panel.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if (key == ' '){
        bShowGui = !bShowGui;
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
