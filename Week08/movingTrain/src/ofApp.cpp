#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetVerticalSync(true);
    
    windowView.setup();
    //windowView2.setup();
    //windowView2.pos.x = windowView.planeScape.getWidth();
    
    
    // foreground image of train
    train.load("images/trainDream3.png");
    train.resize(newWidth * .6,newHeight * .6);
    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    windowView.update();
    // windowView2.update();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(ofColor::whiteSmoke);
    
    windowView.draw();
    // windowView2.draw();
    
    
    // draw the train
    //ofEnableAlphaBlending();
    train.draw(-100, 0);
    
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
