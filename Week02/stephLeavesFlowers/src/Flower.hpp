#include "ofMain.h"

class Flower {
    
public:
    
    void setup();
    void update();
    void draw();
    
    // stuff pertaining to each instance of the Flower class
private:
    
    
    ofColor flowerColor;
    float xPos, yPos;
    float scaleFactor;
    float rotation;
    
    
    float flowerLength, flowerWidth;
    float flowerCurvature;
    
};

