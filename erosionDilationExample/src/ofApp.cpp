#include "ofApp.h"


void ofApp::dilateImage(ofImage & src, ofImage & dst){
    
    // we assume that src and dst have same size...
    // also they are greyscale
    
    for (int i = 0; i < src.getWidth(); i++){
        for (int j = 0; j < src.getHeight(); j++){
            ofColor me = src.getColor(i,j);
            
            if (me.getBrightness() < 127){
                ofColor se = src.getColor(ofClamp(i+1,0, src.getWidth()-1),
                                          ofClamp(j+1, 0, src.getHeight()-1));
                ofColor e =  src.getColor(ofClamp(i+1,0, src.getWidth()-1),
                                          ofClamp(j, 0, src.getHeight()-1));
                ofColor ne = src.getColor(ofClamp(i+1,0, src.getWidth()-1),
                                          ofClamp(j-1, 0, src.getHeight()-1));
                ofColor n = src.getColor(ofClamp(i,0, src.getWidth()-1),
                                         ofClamp(j-1, 0, src.getHeight()-1));
                ofColor nw = src.getColor(ofClamp(i-1,0, src.getWidth()-1),
                                          ofClamp(j-1, 0, src.getHeight()-1));
                ofColor w = src.getColor(ofClamp(i-1,0, src.getWidth()-1),
                                         ofClamp(j, 0, src.getHeight()-1));
                ofColor sw = src.getColor(ofClamp(i-1,0, src.getWidth()-1),
                                          ofClamp(j+1, 0, src.getHeight()-1));
                ofColor s = src.getColor(ofClamp(i,0, src.getWidth()-1),
                                         ofClamp(j+1, 0, src.getHeight()-1));
                if (se.getBrightness() > 127 ||
                    e.getBrightness() > 127 ||
                    ne.getBrightness() > 127 ||
                    n.getBrightness() > 127 ||
                    nw.getBrightness() > 127 ||
                    w.getBrightness() > 127 ||
                    sw.getBrightness() > 127 ||
                    s.getBrightness() > 127 ){
                    
                    me = ofColor::white;
                }
            }
            
            dst.setColor(i,j, me);
            
        }
    }
    
    
}

//--------------------------------------------------------------
void ofApp::setup(){

    imgA.load("zr.jpeg");
    imgA.setImageType(OF_IMAGE_GRAYSCALE);
    // threshold...
    for (int i = 0; i < imgA.getWidth(); i++){
        for (int j = 0; j < imgA.getHeight(); j++){
            if (imgA.getColor(i,j).getBrightness() > 127){
                imgA.setColor(i,j, ofColor::white);
            } else {
                imgA.setColor(i,j, ofColor::black);
            }
        }
    }
    imgA.update();
    
    
    imgB.allocate(imgA.getWidth(), imgA.getHeight(),OF_IMAGE_GRAYSCALE);
    
    
   
    
}

//--------------------------------------------------------------
void ofApp::update(){
    dilateImage(imgA, imgB);
    dilateImage(imgB, imgA);
    
    imgB.update();
}

//--------------------------------------------------------------
void ofApp::draw(){

    imgA.draw(0,0);
    imgB.draw(imgA.getWidth(), 0);
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
