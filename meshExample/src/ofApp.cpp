#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    grabber.setup(640, 480);
}

//--------------------------------------------------------------
void ofApp::update(){

    grabber.update();
}

//--------------------------------------------------------------
void ofApp::draw(){

    grabber.draw(0,0);
    
    
    ofMesh m;
    m.setMode(OF_PRIMITIVE_TRIANGLES);
    m.addVertex(ofPoint(100 + mouseX,100));
    m.addVertex(ofPoint(300+ mouseX,100));
    m.addVertex(ofPoint(200+ mouseX,280));
    
    
    m.addColor(ofColor(255,255,255,0));
    m.addColor(ofColor(255,255,255,255));
    m.addColor(ofColor(255,255,255,255));
    
//    m.addColor(ofColor::white);

//    m.addTexCoord( grabber.getTexture().getCoordFromPoint(100, 100));
//    m.addTexCoord( grabber.getTexture().getCoordFromPoint(300, 100));
//    m.addTexCoord( grabber.getTexture().getCoordFromPoint(200, 280));
//
    //grabber.getTexture().bind();
    m.draw();
    //grabber.getTexture().unbind();
    
    
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
