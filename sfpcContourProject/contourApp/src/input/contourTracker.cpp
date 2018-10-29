

#include "contourTracker.h"

//---------------------------------------------------------------
void contourTracker::setup(){
}


//---------------------------------------------------------------
void contourTracker::analyze( ofPolyline & curFrame ){
    
    
    ofPolyline line = curFrame;
 
    
    // A++ if you fix getResampledByCount end points !
    //
    
    ofPolyline resampled = line.getResampledByCount( 180);
    
    while(resampled.size() < 180){
        resampled.getVertices().push_back(resampled[resampled.size()-1]);
    }
    
 
    if (prevFrame.size() > 0){
        
        // if you want to make this faster
        // you will get an A +
        // this is pretty slow :(
        // but it works.
        
        int smallestStart = -1;
        float smallestAvgLen = 10000000;
        
        for (int i = 0; i < 180; i++){
            
            float avgLen = 0;
            for (int j = 0; j < 180; j++){
                avgLen += (resampled[ (j + i ) % 180] - prevFrame[j]).length() / 180.0;
            }
            if (avgLen < smallestAvgLen){
                smallestAvgLen = avgLen;
                smallestStart = i;
            }
            
        }
        
        ofPolyline temp;
        for (int i = 0; i < 180; i++){
            temp.addVertex( resampled[ (i + smallestStart) % 180]);
        }
        resampled = temp;
        
        
        
    }
    
    ofPolyline tempT = resampled.getResampledByCount(100);
    
    while(tempT.size() < 100){
        tempT.getVertices().push_back(tempT[tempT.size()-1]);
    }
    
    if (resampleSmoothed.size() == 0){
        resampleSmoothed = tempT;
    } else {
        for (int i = 0; i < 100; i++){
            resampleSmoothed[i] = 0.75f * resampleSmoothed[i] + 0.25f * tempT[i];
        }
    }
    
    for (auto p : resampleSmoothed.getVertices()){
        
        unsigned int nearestIndex = 0;
        resampled.getClosestPoint(p, &nearestIndex);
        
        
    }
    
    
    prevFrame = resampled;

}


//---------------------------------------------------------------
void contourTracker::draw(){
}