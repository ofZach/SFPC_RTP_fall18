#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    
    nodeA.setPosition(0,0,0);
    
    nodeB.setParent(nodeA);
    nodeB.setPosition(200,0,0);
    
    
    nodeC.setParent(nodeB);
    nodeC.setPosition(100, 0,0);
    
}

//--------------------------------------------------------------
void ofApp::update(){

    nodeA.roll(sin(ofGetElapsedTimef()*0.7) * 5);
    nodeB.pan(sin(ofGetElapsedTimef()) * 5);
    line.addVertex(nodeC.getGlobalPosition());
    if (line.size() > 400){
        line.getVertices().erase(line.getVertices().begin());
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

    cam.begin();
//    nodeA.draw();
//    nodeB.draw();
//    nodeC.draw();
    ofCircle(nodeA.getGlobalPosition(), 5);
    ofCircle(nodeB.getGlobalPosition(), 5);
    ofCircle(nodeC.getGlobalPosition(), 5);
    ofLine(nodeA.getGlobalPosition(), nodeB.getGlobalPosition());
    ofLine(nodeB.getGlobalPosition(), nodeC.getGlobalPosition());
    line.draw();
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
