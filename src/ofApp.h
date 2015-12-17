#pragma once

#include "ofMain.h"
#include "menu.h"
#include "ofxOsc.h"
#include "ofxGui.h"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

//---OSC SENDERS
    ofxOscSender oscSender;//control general
    ofxOscSender oscZ1;//zona1
    ofxOscSender oscZ2;//zona2
    ofxOscSender oscZ3;//zona3
    ofxOscSender oscZ4;//zona4
//--Presencias Controls
    bool z1;
    bool z2;
    bool z3;
    bool z4;
    bool z5;
//--Faders as Function
    void fadeInCh1 ();
    void fadeInCh2 ();
    void fadeOutCh1 ();
    void fadeOutCh2 ();
//--General funcions
    void inicio();
    void stepUno();
    void killAll();
    void controlZonas();
    
		void keyPressed(int key);
        menu menu;
    float startTime;
    bool timerEnd;
    ofParameter<int>endTime;
    ofParameter<int>fadeIn;
    ofParameter<int>fadeOut;
    ofxPanel gui;
		
};
