#include "ofMain.h"

class Soup
{
public:
    void setup();
    void update();
    void draw();
    
private:
    ofImage family;
    ofVideoPlayer sparkle;
    ofVec2f pos,vel;
    
};