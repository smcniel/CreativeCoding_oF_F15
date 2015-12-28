

#include "Soup.hpp"

void Soup::setup()
{
    family.load("image/soup2.png");
    
    sparkle.load("image/sparkle.mp4");
    sparkle.setLoopState(OF_LOOP_NORMAL);
    sparkle.play();
    
    
}


void Soup::update()
{
    sparkle.update();
}


void Soup::draw()
{
    
    if (sparkle.isLoaded()) {
        sparkle.draw(100, 10);
    }
    
    family.draw(0,0);
    
}