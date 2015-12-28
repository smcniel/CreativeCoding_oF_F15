#pragma once

#include "ofMain.h"
#include "Meow.hpp"
#include "Circle.hpp"
#include "Portrait.hpp"
#include "Jellyfish.hpp"
#include "Soup.hpp"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        int wallpaper;
    
        // main image
        ofImage chair;
    
        // wallpaper 1
        int xMargin, yMargin;
        int numColumns, numRows;
        vector<Circle> circles;
    
        // wallpaper 2
        Portrait myPortrait;
    
    
        // wallpaper 3
        Soup mySoup;
    
    
        // wallpaper 4
        vector<Meow> meows;
        int numMeowColumns, numMeowRows;
        int xMeowMargin, yMeowMargin;
    
        // wallpaper test
        //Jellyfish myJellyfish;
    
		
};
