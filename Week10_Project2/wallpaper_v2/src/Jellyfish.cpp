

#include "Jellyfish.hpp"

void Jellyfish::setup(float _xPos, float _yPos)
{
    pos.x = _xPos;
    pos.y = _yPos;
    circleColor = ofColor(15, 120, 220);
    diameter = 30;
    resolution = 360;
}

void Jellyfish::update()
{
    
}

void Jellyfish::draw()
{
    ofPushStyle();
    ofPushMatrix();
    ofSetLineWidth(1);
    ofBeginShape();
    float x0 = pos.x;
    float x1 = x0 + diameter/2;
    float x2 = x0 - diameter/2;
    
    
    float y0 = pos.y;
    //    float y1 = y0 - diameter/2;
    //    float y2 = y1/2;
    //    float y3 = diameter;
    
    ofSetColor(circleColor);
    for(int i = 0; i < resolution; i++) {
        float angle = i * M_PI/resolution;
        ofVertex(x0 + (cos(angle) * diameter/2), y0 - (sin(angle) * diameter/2));
    }
    
    ofDrawCircle(x0, y0, 5);
    ofDrawCircle(x1, y0, 5);
    ofDrawCircle(x2, y0, 5);
    
    ofEndShape();
    ofPopMatrix();
    ofPopStyle();
    
    
    
}