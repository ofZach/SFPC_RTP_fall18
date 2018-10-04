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
    
    ofTranslate(300, 300);
    
    // vector = growable array (dynamic)
    // ofPath -- shape object in OF -- more info polyline
    vector < ofPath > letters = font.getStringAsPoints("muriel");
    
    for (int i = 0; i < letters.size(); i++){
        vector < ofPolyline > outlines = letters[i].getOutline();
        for (int j = 0; j < outlines.size(); j++){
            //outlines[j].draw();
            ofPolyline temp = outlines[j].getResampledBySpacing(1);
            temp = temp.getSmoothed(mouseX);
            temp.draw();
//            for (int k = 0; k < outlines[j].size(); k++){
//                ofCircle( outlines[j][k], 3);
//            }
        }
        
    }
    
    
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
