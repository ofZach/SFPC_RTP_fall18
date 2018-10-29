#include "ofApp.h"
#include "emptyScene.h"
#include "spikeScene.h"
#include "randomLineScene.h"


//--------------------------------------------------------------
void ofApp::setup(){

    
    IM.setup();
    
    SM.scenes.push_back(new emptyScene());
    SM.scenes.push_back(new spikeScene());
    SM.scenes.push_back(new randomLineScene());
    
    // share a pointer to the CT object 
    for (int i = 0; i < SM.scenes.size(); i++){
        SM.scenes[i]->CT = &CT;
    }
    
    SM.setup();
    
    
    bDrawDebug = false;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    IM.update();
    
    
    ofRectangle input(0,0,IM.medianFilteredResult.getWidth(), IM.medianFilteredResult.getHeight());
    ofRectangle output(0,0, ofGetWidth(), ofGetHeight());
    
    ofRectangle inputScaled = input;
    inputScaled.scaleTo(output);
    
    
    
    if (IM.finder.size() > 0){
     
        ofPolyline tempLine = IM.finder.getPolyline(0);
        for (int i = 0; i < tempLine.size(); i++){ 
            float x = tempLine[i].x;
            float y = tempLine[i].y;
            float newX = ofMap(x, input.x, input.x + input.width,
                               inputScaled.x + inputScaled.width, inputScaled.x);
            float newY = ofMap(y, input.y, input.y + input.height,
                               inputScaled.y, inputScaled.y + inputScaled.height);
            tempLine[i].set(newX, newY);
            
        }
        CT.analyze(tempLine);
    }
    
    SM.update();
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(0,0,0);
    
    
    if (bDrawDebug){
        IM.draw();
    }else {
        SM.draw();
        
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if (key == OF_KEY_RIGHT){
        SM.nextScene();
    }
    
    if (key == ' '){
        bDrawDebug = !bDrawDebug;
    }
    
    if (key == 'f'){
        ofToggleFullscreen();
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
