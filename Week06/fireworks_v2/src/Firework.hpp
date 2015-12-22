#pragma once
#include "ofMain.h"

class Firework  {
    
    static const int FIREWORK_PARTICLES = 50;
    
public:
    
    void setup();
    void update();
    void draw();
    void move();
    void explode();

    
    
private:
    
    float gravity;
    float baselineYSpeed;
    float maxYSpeed;
    float x[FIREWORK_PARTICLES];
    float y[FIREWORK_PARTICLES];
    float xSpeed[FIREWORK_PARTICLES];
    float ySpeed[FIREWORK_PARTICLES];
    //
    float red;
    float blue;
    float green;
    float alpha;
    
    float particleSize;
    Boolean hasExploded;
    
};


