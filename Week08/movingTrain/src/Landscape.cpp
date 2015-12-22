
#include "Landscape.hpp"

void landscape::setup() {
    
    pos.x = 550;
    pos.y = 220;
    
    mountain.load("images/Mountain3.jpg");
    planeScape.set(3329/2,900/2, 2, 2);
    planeScape.setPosition(pos.x, pos.y, 0);
    planeScape.mapTexCoords(0,0, 3329,900);
    
    vel.x = 0.4;
    ofEnableSmoothing();
    ofDrawBitmapString(ofToString(ofGetFrameRate()/200)+"fps", 10, 15);
    //    vel.y = ofRandom(-3, 3);
    
}

void landscape::update() {
    
    pos.x = pos.x -= vel.x;
    //    planeScape.setPosition(pos.x, pos.y, 0);
    
    if (pos.x <= 800) {
        planeScape.setPosition(pos.x, pos.y, 0);
    }
    
    
    
}

void landscape::draw() {
    
    
    // bind mountain onto plane as texture and draw
    ofPushMatrix();
    mountain.bind();
    planeScape.draw();
    mountain.unbind();
    ofPopMatrix();
    
    
}

