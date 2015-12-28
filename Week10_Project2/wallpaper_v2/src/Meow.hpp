
#include "ofMain.h"

class Meow
{
    
public:
    void setup(float _xPos, float _yPos);
    void update();
    void draw();
    
private:
    //float xPos, yPos;
    ofPoint pos;
    ofImage kitten;
    //ofPixels kittenPixels;
    int radius;
    
    
    ofTexture circleTexture;
    vector <ofPoint> NormCirclePts;
    vector <ofPoint> NormCircleCoords;
    
    // taken from particles example
    ofPoint vel;
    ofPoint force;
    float drag;
    vector <ofPoint> * attractPoints;
    
    ofSoundPlayer catMeow;
    
};

