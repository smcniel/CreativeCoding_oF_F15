
#include "Flower.hpp"



void Flower::setup(){
    xPos = ofGetWidth()/2; //set to middle of screen in the horizontal
    yPos = ofGetHeight()/2; //set to 3/4 of the way from the top of the screen in the vertical
    
    
    flowerColor = ofColor(ofRandom(200,250),ofRandom(10,20),ofRandom(50,60), ofRandom(100,125));
    //ofRandom(150,255));
    scaleFactor = ofRandom(.5,1.0);
    ofSetRectMode(OF_RECTMODE_CENTER);
    flowerLength = ofRandom(100,200);
    flowerWidth = ofRandom(50,100);
    flowerCurvature = ofRandom(1, 5);
    rotation = ofRandom(0, 360);
}

void Flower::update(){
    
}

void Flower::draw(){
    
    ofPushMatrix();
    ofTranslate(xPos, yPos);
    ofScale(scaleFactor, scaleFactor);
    ofRotateZ(rotation);
    
    //draw leaf
    
    ofSetColor(flowerColor);
    
    //draw left half of leaf
    
    ofBeginShape();
    
    float x0 = 0;
    float x1 = x0 - flowerWidth;
    float x2 = x0 - flowerWidth/flowerCurvature;
    float x3 = x0;
    
    float y0 = 0;
    float y1 = y0 - flowerLength/3;
    float y2 = y1 - flowerLength/3;
    float y3 = y0 - flowerLength;
    
    ofVertex(x0,y0);
    ofBezierVertex(x1,y1,x2,y2,x3,y3);
    
    ofEndShape();
    
    //draw right half of leaf
    
    ofBeginShape();
    
    x0 = 0; //don't need to redefine as float, because we are just reusing the variables created above
    x1 = x0 + flowerWidth;
    x2 = x0 + flowerWidth/flowerCurvature;
    x3 = x0;
    
    y0 = 0;
    y1 = y0 - flowerWidth/3;
    y2 = y1 - flowerWidth/3;
    y3 = y0 - flowerLength;
    
    ofVertex(x0,y0);
    ofBezierVertex(x1,y1,x2,y2,x3,y3);
    
    ofEndShape();
    
    
    ofPopMatrix();
    
    
}
