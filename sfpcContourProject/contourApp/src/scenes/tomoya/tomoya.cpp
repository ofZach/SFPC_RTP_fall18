

#include "tomoya.h"

//---------------------------------------------------------------
void tomoya::setup(){
    data = new float[100*4*2];
    cout << CT->resampleSmoothed.size()<<endl;
    main.allocate(ofGetWidth(), ofGetHeight(),GL_RGBA32F);
    datafbo.allocate(ofGetWidth(), ofGetHeight(),GL_RGBA32F);
    datafbo2.allocate(ofGetWidth(), ofGetHeight(),GL_RGBA32F);

    datashader.load("tomoya_shader/datashader");
    datashader2.load("tomoya_shader/datashader2");

    shader.load("tomoya_shader/myshader");
    blurx.load("tomoya_shader/ShaderBlurX");
    blury.load("tomoya_shader/ShaderBlurY");
    
    
    main.begin();
    bool tmpcolor=true;
    int lenx = 19;
    int leny = 19;
    for(int i =0;i<lenx;i++){
            for(int j =0;j<leny;j++){
            int b = (tmpcolor)? 0:255;
        ofSetColor(b);
        ofDrawRectangle(ofGetWidth()*i/lenx, ofGetHeight()*j/leny, ofGetWidth()/lenx, ofGetHeight()/leny);
                tmpcolor = !tmpcolor;
            }}
    main.end();
    datafbo.begin();
    ofSetColor(0);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    datafbo.end();
    datafbo2.begin();
    ofSetColor(0);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    datafbo2.end();

}


//---------------------------------------------------------------
void tomoya::update(){

    //the info you want is here:
//    CT->resampleSmoothed.
    currentframe = CT->prevFrame.getResampledByCount(100);
    while (currentframe .size() < 100){
        currentframe.getVertices().push_back(currentframe[currentframe.size()-1]);
    }
    if(pastframe.size() <currentframe.size()){
        pastframe = currentframe;
    }
    for(int i = 0;i<100; i++){
        currentpt[i] = ofVec2f(currentframe[i]);
        pastpt[i] =ofVec2f(pastframe[i]);
    }
    datafbo.begin();
    datashader.begin();
    datashader.setUniform1f("scale",1);
    datashader.setUniform2fv("current",&currentpt[0].x,100);
    datashader.setUniform2fv("past",&pastpt[0].x,100);
    ofSetColor(255);
//    ofDrawRectangle(0,0,ofGetWidth(),ofGetHeight());
    datafbo.draw(0,0);
    datashader.end();
    datafbo.end();
    
    datafbo2.begin();
    datashader2.begin();
    datashader2.setUniformTexture("accel", datafbo.getTexture(), 1);
    datashader2.setUniform2fv("current",&currentpt[0].x,100);
    datashader2.setUniform2fv("past",&pastpt[0].x,100);
    ofSetColor(255);
    datafbo2.draw(0,0);
    datashader2.end();
    blurx.begin();
    blurx.setUniform1f("blurAmnt", 1.5);
    datafbo2.draw(0,0);
    blurx.end();
    blury.begin();
    blury.setUniform1f("blurAmnt", 1.5);
    datafbo2.draw(0,0);
    blury.end();
    datafbo2.end();
    
    main.begin();
    shader.begin();
    shader.setUniformTexture("velocity", datafbo2.getTexture(), 1);
    main.draw(0,0);
    shader.end();
    main.end();
    
}


//---------------------------------------------------------------
void tomoya::draw(){

    ofDrawBitmapString("Tomoya Scene", 10, 10);
//    std::string mystr = "num of partices: " + std::to_string(CT->resampleSmoothed.size());
//    ofDrawBitmapString(mystr, 10, 20);
    if(ofGetMouseX()<(ofGetWidth()/3)){
    main.draw(0,0);
    }else if(ofGetMouseX()>(ofGetWidth()/3) && ofGetMouseX()<(ofGetWidth()*2/3)){
        datafbo2.draw(0,0);
    }else{
         datafbo.draw(0,0);
    }
    
//    for(int i = 0;i< currentframe.size(); i++){
//        ofVec2f p1 =currentframe[i];
//
//                ofDrawCircle(p1, 10);
//
//    }
    
//    CT->resampleSmoothed.draw();
    pastframe =currentframe;
 }
