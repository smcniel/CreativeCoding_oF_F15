#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0,0,0);
    
    // set higher to make the trails
    ofSetFrameRate(60);

//    ofEnableAlphaBlending();
//    ofEnableSmoothing();
    
    // disable background clearing for trails
    ofSetBackgroundAuto(false);
    
    // Allocate the fbo
    fireworkFbo.allocate(1024, 768, GL_RGBA);
    
    // clear fbo of junk
    fireworkFbo.begin();
    ofClear(255,255,255, 0);
    fireworkFbo.end();
    
    //myfirework.setup();

}

void ofApp::systemStart(){
    
    
    myfirework.setup();
        
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    ofEnableAlphaBlending();
    
//    if( ofGetKeyPressed('c') ){
//        fireworkFbo.begin();
//        ofClear(255,255,255, 0);
//        fireworkFbo.end();
//         }
    
    fireworkFbo.begin();
        
    drawFireworkFbo();
    fireworkFbo.end();
   

    
}

//--------------------------------------------------------------
void ofApp::drawFireworkFbo(){
    //we clear the fbo if c is pressed.
    //this completely clears the buffer so you won't see any trails
    if( ofGetKeyPressed('c') ){
        
        ofClear(255,255,255, 0);
        
    }
    
    // the lower the number, the longer the trails will take to fade
    // away.
    fadeAmnt = 5;
    
    
    //1 - Fade Fbo
    //by drawing a rectangle the size of the fbo with a small alpha value, we can slowly fade the current contents of the fbo.
    ofFill();
    ofSetColor(0,0,0, fadeAmnt);
    ofDrawRectangle(0,0,ofGetWidth(),ofGetHeight());
    
    //2 - Draw graphics
    myfirework.draw();
    
    
    
}


//--------------------------------------------------------------
void ofApp::draw(){
    
    
    fireworkFbo.draw(0,0);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
   systemStart();
//    fireworkFbo.begin();
//    ofClear(255,255,255, 0);
//    fireworkFbo.end();
    
    
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
    
}
