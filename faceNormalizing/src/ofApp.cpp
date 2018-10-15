#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    grabber.setup(1280,720);
    
    // Setup tracker
    tracker.setup();
}

//--------------------------------------------------------------
void ofApp::update(){

    grabber.update();
    
    // Update tracker when there are new frames
    if(grabber.isFrameNew()){
        tracker.update(grabber);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

    //grabber.draw(0, 0);
    
    // Draw tracker landmarks
    //tracker.drawDebug();
    
    if (tracker.size() > 0){
        ofPolyline left = tracker.getInstances()[0].getLandmarks().getImageFeature(ofxFaceTracker2Landmarks::LEFT_EYE);
        ofPolyline right = tracker.getInstances()[0].getLandmarks().getImageFeature(ofxFaceTracker2Landmarks::RIGHT_EYE);
        
        ofPoint midLeft;
        ofPoint midRight;
        for (int i = 0; i < left.size(); i++){
            midLeft += left[i];
        }
        
        for (int i = 0; i < right.size(); i++){
            midRight += right[i];
        }
        midLeft /= (float)left.size();
        midRight /= (float)right.size();
        ofCircle(midLeft, 3);
        ofCircle(midRight, 3);
        //ofLine(midLeft, midRight);
        ofPoint diff = midRight- midLeft;
        float dist = diff.length();
        float scale = 200.0 / MAX(dist, 0.001);
        float angle = atan2(diff.y, diff.x);
        
        grabber.setAnchorPoint(midLeft.x, midLeft.y);
        ofPushMatrix();
        ofTranslate(200,200);
        ofRotateZ( -angle * RAD_TO_DEG);
        ofScale(scale, scale);
        grabber.draw(0,0);
        ofPopMatrix();
        grabber.setAnchorPoint(0, 0);
        //left.draw();
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
