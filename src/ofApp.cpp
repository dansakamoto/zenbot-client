#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(220, 220, 200);
    
    // open an outgoing connection to HOST:PORT
    sender.setup(host, PORT);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    // display instructions
    string buf;
    ofDrawBitmapString("Moving mouse moves the rake.", 10, 20);
    ofDrawBitmapString("Clicking lowers rake.", 10, 35);
    buf = "Sending to " + string(host);
    ofDrawBitmapString(buf, 10, 65);
    ofDrawBitmapString("Press A to send to different address.", 10, 80);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
   
    if (key == 'a'){
        host = ofSystemTextBoxDialog("Robot Arm IP Address", host);
        sender.setup(host, PORT);
    }
}


//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
    ofxOscMessage m;
    m.setAddress("/mouse/position");
    
    float xf;
    float yf;
    bool toSend = true;
    
    
    if(x <= 0 || x >= ofGetWindowWidth()){
        toSend = false;
    } else {
        xf = ((float)x/ofGetWindowWidth());
    }
    
    if(y <= 0 || y >= ofGetWindowHeight()){
       toSend = false;
    } else {
        yf = 1-((float)y/ofGetWindowHeight());
        if(toSend){
            toSend = true;
        }
    }
    
    if(toSend){
        m.addFloatArg(yf);
        m.addFloatArg(xf);
        m.addIntArg(0);
        sender.sendMessage(m, false);
    }

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    ofxOscMessage m;
    m.setAddress("/mouse/position");
    
    float xf;
    float yf;
    bool toSend = true;
    
    
    if(x <= 0 || x >= ofGetWindowWidth()){
        toSend = false;
    } else {
        xf = ((float)x/ofGetWindowWidth());
    }
    
    if(y <= 0 || y >= ofGetWindowHeight()){
        toSend = false;
    } else {
        yf = 1-((float)y/ofGetWindowHeight());
        if(toSend){
            toSend = true;
        }
    }
    
    if(toSend){
        m.addFloatArg(yf);
        m.addFloatArg(xf);
        m.addIntArg(1);
        sender.sendMessage(m, false);
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

    ofxOscMessage m;
    m.setAddress("/mouse/button");
    m.addIntArg(1);
    sender.sendMessage(m, false);

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

    ofxOscMessage m;
    m.setAddress("/mouse/button");
    m.addIntArg(0);
    sender.sendMessage(m, false);
    
    
}

