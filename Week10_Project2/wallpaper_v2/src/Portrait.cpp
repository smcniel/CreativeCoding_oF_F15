
#include "Portrait.hpp"

void Portrait::setup()
{
    face.load("image/portrait2.png");
    
    clouds.load("image/clouds3.mp4");
    clouds.setLoopState(OF_LOOP_NORMAL);
    clouds.play();
    
    
}


void Portrait::update()
{
    clouds.update();
}


void Portrait::draw()
{
    
    if (clouds.isLoaded()) {
        clouds.draw(300, 10);
    }
    
    face.draw(0,0);

}