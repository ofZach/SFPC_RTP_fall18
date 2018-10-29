

#include "spikeScene.h"

//---------------------------------------------------------------
void spikeScene::setup(){
    

}


//---------------------------------------------------------------
void spikeScene::update(){
   
    //the info you want is here:
    //CT->resampleSmoothed

}


//---------------------------------------------------------------
void spikeScene::draw(){
    
    
    CT->resampleSmoothed.draw();

    for (int i = 0; i < CT->resampleSmoothed.size(); i++){
        
        int i_m_1 = i-1;
        int i_p_1 = i+1;
        if (i_m_1 < 0) i_m_1 += CT->resampleSmoothed.size();
        i_p_1 %=  CT->resampleSmoothed.size();
        
        ofPoint a = CT->resampleSmoothed[i_m_1];
        ofPoint b = CT->resampleSmoothed[i_p_1];
        ofPoint diff = b-a;
        diff = diff.getNormalized();
        diff.rotate(-90, ofPoint(0,0,1));
        ofLine(CT->resampleSmoothed[i], CT->resampleSmoothed[i] + diff* 100);
        //ofCircle(CT->resampleSmoothed[i], 3);
    }
}
