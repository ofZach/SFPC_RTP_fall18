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
    
    
    //ofSetColor(80);
    //font.drawString("hello", 100,100);
    
//    ofDrawLine(100,100,200,100);
//    ofRectangle r = font.getStringBoundingBox("hello", 100, 100);
//    ofNoFill();
//    ofDrawRectangle(r);
    
    ofTranslate(100,100);
    vector < ofPath > paths = font.getStringAsPoints("hello");
    for (int i = 0; i < paths.size(); i++){
        
        vector < ofPolyline > lines = paths[i].getOutline();
        //cout << lines.size() << endl;
        
        ofSetColor(255);
        for (int j = 0; j < lines.size(); j++){
            ofPolyline lineTemp = lines[j];
            lineTemp = lineTemp.getResampledBySpacing(1);
            lineTemp = lineTemp.getSmoothed( MAX(0, mouseX));
//            for (int k = 0; k < lineTemp.size(); k++){
//                ofDrawCircle(lineTemp[k], 2);
//            }
            lineTemp.draw();
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
