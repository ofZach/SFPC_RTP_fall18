

#include "randomLineScene.h"

//---------------------------------------------------------------
void randomLineScene::setup(){
    

}


//---------------------------------------------------------------
void randomLineScene::update(){
   
    //the info you want is here:
    //CT->resampleSmoothed

}


//---------------------------------------------------------------
void randomLineScene::draw(){
    
    
    //CT->resampleSmoothed.draw();

    ofSeedRandom(ofGetSeconds()*1000);
    for (int i = 0; i < CT->resampleSmoothed.size(); i++){
        int who = ofRandom(0, CT->resampleSmoothed.size());
        ofDrawLine(CT->resampleSmoothed[i],
                   CT->resampleSmoothed[who]);
    }
    
    
    
}
