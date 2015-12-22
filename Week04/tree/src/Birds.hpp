
#include "ofMain.h"

class Birds : public ofBaseApp {
    
public:
    
    void setup();
    void update();
    void draw();
    
    // stuff pertaining to each instance of the Birds class
private:
    
    ofColor bodyColor;
    ofColor wingColor;
    ofColor wing2Color;
    
    ofVec2f pos;
    float scaleFactor;
   
    
    
};



