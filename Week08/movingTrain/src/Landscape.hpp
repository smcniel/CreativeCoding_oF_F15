#pragma once

#include "ofMain.h"

class landscape {
    
public:
    void setup();
    void update();
    void draw();
    
    
    ofVec2f pos,vel;
    ofImage mountain;
    ofPlanePrimitive planeScape;
    
};