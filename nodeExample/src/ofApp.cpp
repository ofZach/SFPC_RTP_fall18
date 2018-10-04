#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    a.setPosition(0,0,0);
    b.setParent(a);
    b.setPosition(200,0,0);
    c.setParent(b);
    c.setPosition(0,200,0);
    
    a2.setPosition(0,0,0);
    b2.setParent(a2);
    b2.setPosition(200,0,0);
    c2.setParent(b2);
    c2.setPosition(0,200,0);
}

//--------------------------------------------------------------
void ofApp::update(){

    float ff =ofGetElapsedTimef();
    for (int i = 0; i < 120; i++){
        
        time +=  ofMap(sin(ff), -1, 1, 0.001,    0.0001);
        ofPoint cc = b.getGlobalPosition() + c.getGlobalPosition();
        a.panDeg( 3 * ofSignedNoise(cc.x * 0.001 +time*0.5));
        //b.rollDeg( 4.4 * sin(ofGetElapsedTimef()));
        b.rollDeg( 2 * ofSignedNoise(cc.y * 0.0001 + time*0.5));
        
        line.addVertex(c.getGlobalPosition());
        if (line.size() > 2400){
            line.getVertices().erase(line.getVertices().begin());
        }
        
        ofPoint cc2 = b2.getGlobalPosition() + c2.getGlobalPosition();
        a2.panDeg( 3 * ofSignedNoise(cc2.x * 0.0011 + time*0.5));
        b2.rollDeg(2.1 * ofSignedNoise(cc2.y * 0.0002 + time*0.5));
        
        line2.addVertex(c2.getGlobalPosition());
        if (line2.size() > 2400){
            line2.getVertices().erase(line2.getVertices().begin());
        }
        
        
        b2.setPosition(200 + 120 * sin(cc2.y * 0.0011+ time*0.5),0,0);
        b.setPosition(200 + 200 * sin(cc.y * 0.0011+ time*0.5),0,0);
        
        c2.setPosition(200 + 100 * sin(cc2.z * 0.0001+ time*0.5),0,0);
        c.setPosition(200 + 200 * sin(cc.z * 0.0001+ time*0.5),0,0);
    }
    
    line2 = line2.getSmoothed(22);
    
    line = line.getSmoothed(22);
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    cam.enableOrtho();
    ofBackground(0);
    cam.begin();
    ofRotateY(ofGetElapsedTimef()*10.0);
//    a.draw();
//    b.draw();
//    c.draw();
//    ofLine(a.getGlobalPosition(), b.getGlobalPosition());
//    ofLine(b.getGlobalPosition(), c.getGlobalPosition());
    
//    line.draw();
//    line2.draw();
    ofEnableDepthTest();
    ofMesh m;
    m.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
    for (int i = 0; i < line.size(); i++){
        float pct = ofMap(i, 0, line.size(), 0, 1);
        //ofLine(line[i], line2[i]);
        m.addVertex(line[i]);
        m.addVertex(line2[i]);
        m.addColor(ofColor(0));
        m.addColor(ofColor(pct*0));
        
    }
    ofSetLineWidth(3);
    ofTranslate(0,0,-1);
    m.draw();
    ofSetColor(255);
        line.draw();
        line2.draw();
    
    for (int i = 0; i < line.size(); i+=30){
        //float pct = ofMap(i, 0, line.size(), 0, 1);
        //ofLine(line[i], line2[i]);
    }
    cam.end();
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    line.clear();
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
