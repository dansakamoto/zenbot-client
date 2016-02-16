#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

//#define HOST "128.237.214.36"
#define PORT 12345

//--------------------------------------------------------
class ofApp : public ofBaseApp {
    
public:
    string host = "128.237.201.233";
    
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    
    ofTrueTypeFont font;
    ofxOscSender sender;
    ofBuffer imgAsBuffer;
    ofImage img;
    
    int winPosX;
    int winPosY;
    int winWidth;
    int winHeight;
};

