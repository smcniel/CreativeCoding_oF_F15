

#include "Meow.hpp"

void Meow::setup(float _xPos, float _yPos)
{
    
    //ofEnableNormalizedTexCoords();
    pos.x = _xPos;
    pos.y = _yPos;
    
    // load sound
    catMeow.load("sounds/cat-meow.wav");
    
    // load image
    kitten.load("image/kitten2.jpg");
    radius = 20;
    
    int width = kitten.getWidth();
    int height = kitten.getHeight();
    circleTexture.allocate(width, height, GL_RGB);
    circleTexture.loadData(kitten);
    
    int numPts  = 64;
    float angle = 0.0;
    float step  = TWO_PI / (float)(numPts-1);
    
    for(int i = 0; i < numPts; i++){
        
    //get the -1 to 1 values - we will use these for drawing our pts.
    float px = cos(angle);
    float py = sin(angle);
        
    NormCirclePts.push_back( ofPoint(px, py) );
        
    //map the -1 to 1 range produced by cos/sin
    //to the dimensions of the image we need for our texture coords
    float tx = ofMap( px, -1.0, 1.0, 0, circleTexture.getWidth());
    float ty = ofMap( py, -1.0, 1.0, 0, circleTexture.getHeight());
    
    NormCircleCoords.push_back( ofPoint(tx, ty));
        
    angle += step;
    }
    vel.x = ofRandom(-3.9, 3.9);    // taken from Particles example
    vel.y = ofRandom(-3.9, 3.9);
    force = ofPoint(0,0,0);
    drag  = ofRandom(0.95, 0.998);



}




    


    
    



        
    
    


void Meow::update()
{
    // update the sound playing system:
    ofSoundUpdate();
    
    // update meow position to repel away from the mouse
    ofPoint attractPt(ofGetMouseX(), ofGetMouseY());
    force = attractPt - pos;
    
    // get the distance and only repel points close to the mouse
    float dist = force.length();
    force.normalize();
    
    vel *= drag;
    if( dist < 150 ){
        vel += -force * 0.6; //notice the frc is negative
        if (catMeow.getIsPlaying() == false){
            catMeow.play();
        }
    }
    
    pos += vel;
    
    // update position to stay on screen
    if( pos.x > ofGetWidth() ){
        pos.x = ofGetWidth();
        vel.x *= -1.0;
    }else if( pos.x < 0 ){
        pos.x = 0;
        vel.x *= -1.0;
    }
    if( pos.y > ofGetHeight() ){
        pos.y = ofGetHeight();
        vel.y *= -1.0;
    }
    else if( pos.y < 0 ){
        pos.y = 0;
        vel.y *= -1.0;
    }
    
    
}

void Meow::draw()
{
    ofSetColor(255, 255, 255);
    
    circleTexture.bind();
    
    glBegin(GL_POLYGON);
    for(int i = 0; i < NormCirclePts.size(); i++){
        glTexCoord2f(NormCircleCoords[i].x, NormCircleCoords[i].y);
        glVertex2f( NormCirclePts[i].x * radius + pos.x,  NormCirclePts[i].y * radius + pos.y);
    }
    glEnd();
    
    circleTexture.unbind();
    
}