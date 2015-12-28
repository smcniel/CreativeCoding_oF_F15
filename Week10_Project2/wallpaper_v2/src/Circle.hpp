
#include "ofMain.h"

class Circle
{
    
public:
    Circle();
    void setup(float _xPos, float _yPos);
    void update();
    void draw();
    
private:
    ofPoint pos;
    ofColor circleColor;
    float randomNumber;
    int diameter;
};

