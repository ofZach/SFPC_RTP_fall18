#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    grabber.setup(640,480);
    
    threshold.allocate(640, 480, OF_IMAGE_COLOR);
    
    
    for (int i = 0; i < 30; i++){
        ofPoint pt;
        pt.set(ofRandom(0,640), 0);
        pts.push_back(pt);
    }
}

//--------------------------------------------------------------
void ofApp::update(){

    
    
    
    
    grabber.update();
    
    for (int i = 0; i < 640; i++){
        for (int j = 0; j < 480; j++){
            ofColor pixel = grabber.getPixels().getColor(i,j);
            if (pixel.getBrightness() > mouseX){
                threshold.setColor(i,j, ofColor::white);
            } else {
                threshold.setColor(i,j, ofColor::black);
            }
        }
    }
    threshold.update();
    
    for (int i = 0; i < pts.size(); i++){
    
        int x = ofClamp(pts[i].x, 0, threshold.getWidth()-1);
        int y = ofClamp(pts[i].y, 0, threshold.getHeight()-1);
        ofColor c = threshold.getColor(x,y);
        if (c.getBrightness() > 127){
            pts[i].y += 1;
            if (pts[i].y > 480){
                pts[i].y = 0;
            }
        } else {
            // let's get smart :)
            bool bDidWeFindOne = false;
            for (int j = y; j >= 0; j--){
                ofColor newC = threshold.getColor(x,j);
                if (newC.getBrightness() > 127){
                    // yay!
                    pts[i].y = j;
                    bDidWeFindOne = true;
                    break;
                }
            }
            if (bDidWeFindOne == false){
                pts[i].y  = 0;
            }
        }
    }
    
    
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(255);
    grabber.draw(0,0);
    threshold.draw(640,0);
    
    ofSetColor(255,0,0);
    for (int i = 0; i < pts.size(); i++){
        ofCircle(pts[i], 4);
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
