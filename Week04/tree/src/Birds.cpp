
#include "Birds.hpp"

void Birds::setup(){
    pos.x = (ofRandom(50,ofGetWidth()*5));  //add extra b/c scaling
    pos.y = (ofRandom(50,ofGetHeight()));
    bodyColor = ofColor(ofRandom(100,150),70,10); //brown
    wingColor = ofColor(ofRandom(200,250),ofRandom(10,20),ofRandom(50,60), ofRandom(10,80));
    scaleFactor = ofRandom(.06,.3);
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    //    rotation =  ofRandom(-(PI/2), PI/2); //experiment with the correct limits of rotation
    //
    //    rotation = rotation * (180/PI); //convert to degrees (from radians) to use for ofRotateZ() below, which expects degrees...
    
    
}

void Birds::update(){
    
}

//void Birds::draw(float _xPos, float _yPos){

void Birds::draw(){
    
    ofPushMatrix();
    ofScale(scaleFactor, scaleFactor);
    //    ofRotateZ(rotation);
    
    //bird body
    ofSetColor(bodyColor);
    
    ofBeginShape();
    
    float x0 = pos.x;
    float x1 = x0;
    float x2 = x1 - 40;
    float x3 = x1 + 40;
    float x4 = x1;
    float x5 = x3 - 10;
    float x6 = x3;
    float x7 = x0;
    float x8 = x7 + 10;
    float x9 = x5;
    float x10 = x8;
    float x11 = x10 + 40;
    float x12 = x5;
    
    
    float y0 = pos.y;
    float y1 = y0;
    float y2 = y1 +100;
    float y3 = y1 + 40;
    float y4 = y1;
    float y5 = y4;
    float y6 = y3;
    float y7 = y0;
    float y8 = y7 - 20;
    float y9 = y5;
    float y10 = y8;
    float y11 = y8;
    float y12 = y5;
    
    
    ofVertex(x0,y0);
    ofDrawTriangle(x1, y1, x2, y2, x3, y3);
    ofDrawTriangle(x4, y4, x5, y5, x6, y6);
    ofDrawTriangle(x7, y7, x8, y8, x9, y9);
    ofDrawTriangle(x10, y10, x11, y11, x12, y12);
    
    ofEndShape();
    
    
    // bird wings
    ofSetColor(wingColor);
    ofBeginShape();
    x0 = pos.x;
    x1 = x0 - 70;
    x2 = x1 + 50;
    x3 = x1 +70;
    x4 = x1 - 40;
    x5 = x2;
    x6 = x3;
    
    y0 = pos.y;
    y1 = y0 -40;
    y2 = y1 + 90;
    y3 = y1 + 40;
    y4 = y1 + 30;
    y5 = y2;
    y6 = y3;
    
    ofVertex(x0,y0);
    ofDrawTriangle(x1, y1, x2, y2, x3, y3);
    ofDrawTriangle(x4, y4, x5, y5, x6, y6);
    
    ofEndShape();
    
    
    ofPopMatrix();
    
}

