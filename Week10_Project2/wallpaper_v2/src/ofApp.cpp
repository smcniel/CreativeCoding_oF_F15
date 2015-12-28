#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetVerticalSync(true);
    //ofEnableAlphaBlending();
    ofEnableSmoothing();
    
    // main image load
    chair.load("image/chairWall2.png");
    
    // Circle vectors
    xMargin = 50;
    yMargin = 50;
    numColumns = 10;
    numRows = 10;
    for(int i = 0; i < numColumns; i++){
        for(int j = 0; j < numRows; j++){
            Circle tempCircle;
            float xPosCircle = xMargin + i*((ofGetWidth()-(xMargin*2))/(numColumns-1)); //find x locations based on numColumns
            float yPosCircle = yMargin + j*((ofGetHeight()-(yMargin*2))/(numRows-1));
            tempCircle.setup(xPosCircle,  yPosCircle);
            circles.push_back(tempCircle);
        }
    }
    
    // Portrait with cloud video
    myPortrait.setup();
    
    // Jellyfish-ies
    //myJellyfish.setup(100,100);
    
    // Family eating soup
    mySoup.setup();
    
    
    // Kittens set up similar to circles
    xMeowMargin = 40;
    yMeowMargin = 40;
    numMeowColumns = 8;
    numMeowRows = 8;
    for(int i = 0; i < numMeowColumns; i++){
        for(int j = 0; j < numMeowRows; j++){
            Meow tempMeow;
            float xPosMeow = xMeowMargin + i*((ofGetWidth()-(xMeowMargin*2))/(numMeowColumns-1)); //find x locations based on numColumns
            float yPosMeow = yMeowMargin + j*((ofGetHeight()-(yMeowMargin*2))/(numMeowRows-1));
            tempMeow.setup(xPosMeow,  yPosMeow);
            meows.push_back(tempMeow);
        }
    }
    
    
    



}

//--------------------------------------------------------------
void ofApp::update(){
    
    if(wallpaper == 4){
        // unsigned?  this may have to change
        for(unsigned int i = 0; i < meows.size(); i++){
            meows[i].update();
        }
    }
    myPortrait.update();
    mySoup.update();
    
    
    }

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    if(wallpaper == 1){
        for (int i = 0; i < circles.size(); i++) {
            circles[i].draw();
        }
    }
    
    if(wallpaper == 2){
        myPortrait.draw();
    }
    
    if(wallpaper == 3){
        mySoup.draw();
    }
    
    if(wallpaper == 4){
        ofPushStyle();
        for (int i = 0; i < meows.size(); i++) {
            meows[i].draw();
        }
        
        ofPopStyle();
    }
    
    chair.draw(0,0);
    
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(key == OF_KEY_RIGHT){
        wallpaper = 1;  
    }
    
    if(key == OF_KEY_LEFT){
        wallpaper = 2;
    }
    
    if(key == OF_KEY_UP){
        wallpaper = 3;
    }
    
    if(key == OF_KEY_DOWN){
        wallpaper = 4;
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
