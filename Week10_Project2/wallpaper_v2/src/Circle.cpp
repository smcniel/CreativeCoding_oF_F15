

#include "Circle.hpp"


Circle::Circle()
{
    
}

void Circle::setup(float _xPos, float _yPos)
{
    
    //ofSetCircleResolution(100);
    pos.x = _xPos;
    pos.y = _yPos;
    diameter = 40;
    
    
    randomNumber = ofRandom(0, 17);
    if(randomNumber >= 0 && randomNumber <5){
        circleColor = ofColor(0,ofRandom(200,209),ofRandom(204,215), ofRandom(150,255)); //aqua/turquoise
    }
    if(randomNumber >= 5 && randomNumber < 10) {
        circleColor = ofColor::azure;
    }
    if(randomNumber >= 10 && randomNumber < 15) {
        circleColor = ofColor::blueSteel;
        
    }
    if(randomNumber >= 15 && randomNumber < 16) {
        circleColor = ofColor::gold;
    }
    if(randomNumber >= 16 && randomNumber < 17) {
        circleColor = ofColor::antiqueWhite;
    }
    //    circleColor = ofColor(15, 120, 220);
    
}

void Circle::update()
{
}

void Circle::draw()
{
    //    ofPushStyle();
    //    ofSetColor(circleColor);
    //    ofEllipse(pos.x, pos.y, diameter, diameter);
    //    ofPopStyle();
    
    ofPushStyle();
    float sinOfTime = sin( ofGetElapsedTimef() * 2 );
    float sinOfTimeMapped = ofMap( sinOfTime, -1, 1, 5, 15 );
    ofSetColor(circleColor);
    ofDrawCircle(pos.x, pos.y,  sinOfTimeMapped);
    ofPopStyle();
    
    
}

