#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofDirectory dir;
    dir.listDir("cats");
    
    for (int i = 0; i < dir.size(); i++){
        //cout << dir.getPath(i) << endl;
        ofImage temp;
        imgs.push_back(temp);
        imgs.back().load(dir.getPath(i) );
    }
    
    averageImg.allocate(400, 400, OF_IMAGE_COLOR);
    
    for (int i = 0; i < 400; i++){
        for (int j = 0; j < 400; j++){
            int avgR = 0;
            int avgG = 0;
            int avgB = 0;
            
            for (int k = 0; k < imgs.size(); k++){
                ofColor pixel = imgs[k].getColor(i,j);
                avgR += pixel.r;
                avgG += pixel.g;
                avgB += pixel.b;
                
            }
            avgR /= imgs.size();
            avgG /= imgs.size();
            avgB /= imgs.size();
            
            averageImg.setColor(i,j, ofColor(avgR,avgG, avgB));
            
        }
    }
    averageImg.update();

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    //imgs[ ofGetFrameNum() % 7].draw(0,0);
    averageImg.draw(0,0);
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
