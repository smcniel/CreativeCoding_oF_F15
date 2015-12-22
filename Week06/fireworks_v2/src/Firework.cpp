

#include "Firework.hpp"

// This code is based on the blog post:
// "How To: Create a Simple Fireworks Effect in OpenGL and SDL"
// http://r3dux.org/2010/10/how-to-create-a-simple-fireworks-effect-in-opengl/


void Firework::setup(){
    
    gravity = 0.05f;
    baselineYSpeed = -4.0f;
    maxYSpeed = -4.0f;
    
    // Pick an initial x location and  random x/y speeds
    float xLoc = ofRandom(100, ofGetWidth()-100);
    float xSpeedValue = -2 + (rand() / (float)RAND_MAX) * 4.0f;
    float ySpeedValue = baselineYSpeed + ((float)rand() / (float)RAND_MAX) * maxYSpeed; // find better values for these
    
    
    // Set initial x/y location and speeds
    for (int i = 0; i < FIREWORK_PARTICLES; i++)
    {
        x[i] = xLoc;
        
        // Push the particle location down off the bottom of the screen
        y[i] = ofGetHeight() + 10.0f;
        
        xSpeed[i] = xSpeedValue;
        ySpeed[i] = ySpeedValue;
    }
    
    // Assign a random colour and full alpha (i.e. particle is completely opaque)
    alpha = 1.0f;
    //colorBurst = ofColor(ofRandom(255),ofRandom(255),ofRandom(255), alpha);
    red   = (rand() / (float)RAND_MAX);
    green = (rand() / (float)RAND_MAX);
    blue  = (rand() / (float)RAND_MAX);
    
    
    particleSize = 1.0f;
    
    // Has the firework exploded?
    hasExploded = false;
    
    glPointSize(5.0f);
    
    
}


void Firework::move(){
    
    for (int i = 0; i < FIREWORK_PARTICLES; i++)
    {
        x[i] += xSpeed[i];
        
        y[i] += ySpeed[i];
        
        ySpeed[i] += gravity;
    }
    
    
    // Once a firework's speed turns positive (at top of arc) - blow it up!
    if (ySpeed[0] > 0.0f)
    {
        for (int j = 0; j < FIREWORK_PARTICLES; j++)
        {
            // Set a random x and y speed beteen -4 and + 4
            xSpeed[j] = ofRandom(-4,4);
            ySpeed[j] = ofRandom(-4,4);
        }
        
        cout << "Boom!" << endl;
        hasExploded = true;
    }
    
}

void Firework::explode()
{
    for (int i = 0; i < FIREWORK_PARTICLES; i++)
    {
        // Dampen the horizontal speed by 1% per frame
        xSpeed[i] *= 0.99;
        
        // Move the particle
        x[i] += xSpeed[i];
        y[i] += ySpeed[i];
        
        // Apply gravity to the particle's speed
        ySpeed[i] += gravity;
    }
    
    // Fade out the particles (alpha is stored per firework, not per particle)
//    if (alpha > 0.1f)
//    {
//        alpha -= 0.01f;
//        cout << alpha << endl;
//        if (alpha <= 0.1f){
//        cout << "End" << endl;
//        }
//    }
//    else // Once the alpha hits zero reset the firework
//    {
//        alpha = 0.0f;
//        ofSetColor(0,0,0,0);
//        ofRectangle(0,0,ofGetWidth(),ofGetHeight());
//
//    }
}

void Firework::draw()
{
    for (int i = 0; i < FIREWORK_PARTICLES; i++)
    {
        
        // Set the point size of the firework particles
        glPointSize(particleSize);
        glBegin(GL_POINTS);
        
        // Set colour to yellow on way up, then whatever colour firework should be when exploded
        if (hasExploded == false)
        {
            glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
        }
        else
        {
            glColor4f(red, green, blue, alpha);
        }
        
        // Draw the point
        glVertex2f(x[i], y[i]);
        glEnd();
       
    }
    
    // Move the firework appropriately depending on its explosion state
    if (hasExploded == false)
    {
        move();
    }
    else
    {
        explode();
    }
    
    // Return clean state
    return 0;
}










