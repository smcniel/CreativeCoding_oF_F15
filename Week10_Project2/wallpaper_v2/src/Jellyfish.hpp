
#include "ofMain.h"

class Jellyfish
{
public:
    void setup(float _xPos, float _yPos);
    void update();
    void draw();
    
private:
    
    ofColor circleColor;
    ofPoint pos;
    int diameter;
    int resolution;
    
};