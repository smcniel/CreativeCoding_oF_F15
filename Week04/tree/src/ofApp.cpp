#include "ofApp.h"

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundAuto(false);
    bool hasDrawn = false;
    ofRectMode(RECT_MODE_CENTER);
    season = 0;
    /*
     0 = SUMMER
     1 = FALL
     2 = WINTER
     3 = SPRING
     
     */
    
    
    
    numBirds = 30;
    ////    if(season == 3){
    for(int i = 0; i < numBirds; i++){
        Birds tempBirds;
        tempBirds.setup();
        birds.push_back(tempBirds);
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    //    for (int i = 0; i < birds.size(); i++) {
    //        birds[i].update();
    //    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //    for (int i = 0; i < numBirds; i++) {
    //        birds[i].draw();
    //    }
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    ofBackground(200, 200, 200);
    
    if(key == OF_KEY_RIGHT){
        season = 0;
        
        myBranch.setup(ofGetWidth()/2,      //float _xPos
                       3*(ofGetHeight()/4),     //float _yPos
                       //                   ofGetHeight()/2,     //float _yPos
                       20,                  //float _width
                       70,                  //float _length
                       0.35,                //float _splitPercentage
                       PI/4,                //float _maxSplitAngle
                       2,                   //int _maxSubdivisions
                       5,                   //int _maxSegments
                       0,                   //int _segmentsSinceStart
                       -PI/2,                //float _angle
                       0,                   //float _curvature
                       ofColor(40, 27, 20),//ofColor _color
                       season);
        
        
    }
    if(key == OF_KEY_LEFT){
        season = 1;
        
        myBranch.setup(ofGetWidth()/2,      //float _xPos
                       3*(ofGetHeight()/4),     //float _yPos
                       //                   ofGetHeight()/2,     //float _yPos
                       20,                  //float _width
                       70,                  //float _length
                       0.35,                //float _splitPercentage
                       PI/4,                //float _maxSplitAngle
                       2,                   //int _maxSubdivisions
                       5,                   //int _maxSegments
                       0,                   //int _segmentsSinceStart
                       -PI/2,                //float _angle
                       0,                   //float _curvature
                       ofColor(40, 27, 20),//ofColor _color
                       season);
    }
    
    
    if(key == OF_KEY_UP){
        season = 2;
        
        myBranch.setup(ofGetWidth()/2,      //float _xPos
                       3*(ofGetHeight()/4),     //float _yPos
                       //                   ofGetHeight()/2,     //float _yPos
                       20,                  //float _width
                       70,                  //float _length
                       0.35,                //float _splitPercentage
                       PI/4,                //float _maxSplitAngle
                       2,                   //int _maxSubdivisions
                       5,                   //int _maxSegments
                       0,                   //int _segmentsSinceStart
                       -PI/2,                //float _angle
                       0,                   //float _curvature
                       ofColor(40, 27, 20),//ofColor _color
                       season);
    }
    if(key == OF_KEY_DOWN){
        season = 3;
        
        myBranch.setup(ofGetWidth()/2,      //float _xPos
                       3*(ofGetHeight()/4),     //float _yPos
                       //                   ofGetHeight()/2,     //float _yPos
                       20,                  //float _width
                       70,                  //float _length
                       0.35,                //float _splitPercentage
                       PI/4,                //float _maxSplitAngle
                       2,                   //int _maxSubdivisions
                       5,                   //int _maxSegments
                       0,                   //int _segmentsSinceStart
                       -PI/2,                //float _angle
                       0,                   //float _curvature
                       ofColor(40, 27, 20),//ofColor _color
                       season);
        //        numBirds = 30;
        for (int i = 0; i < numBirds; i++) {
            birds[i].draw();
        }
        //        for(int i = 0; i < numBirds; i++){
        //            Birds tempBirds;
        //            tempBirds.setup();
        //            birds.push_back(tempBirds);
        //        }
        
        
        
        
    }
    
    
    
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
    
    //This is where your Tree begins!
    myBranch.setup(ofGetWidth()/2,      //float _xPos
                   3*(ofGetHeight()/4),     //float _yPos
                   //                   ofGetHeight()/2,     //float _yPos
                   20,                  //float _width
                   70,                  //float _length
                   0.35,                //float _splitPercentage
                   PI/4,                //float _maxSplitAngle
                   2,                   //int _maxSubdivisions
                   5,                   //int _maxSegments
                   0,                   //int _segmentsSinceStart
                   -PI/2,                //float _angle
                   0,                   //float _curvature
                   ofColor(40, 27, 20),//ofColor _color
                   false);
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
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
