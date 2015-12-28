
#include "ofMain.h"

class Portrait
{
public:
    void setup();
    void update();
    void draw();
    
private:
    ofImage face;
    ofVideoPlayer clouds;
    ofVec2f pos,vel;
    
};