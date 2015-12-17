#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetWindowTitle("Controler - V2");
    ofSetWindowShape(640, 550);
    menu.setup();
    ofBackground(ofColor::black);
//---OSC SENDERS
    oscSender.setup("192.168.0.255", 9001);//zonales ip mascara
    oscZ1.setup("192.168.0.11", 9001);//zonales ip1
    oscZ2.setup("192.168.0.12", 9001);//zonales ip2
    oscZ3.setup("192.168.0.13", 9001);//zonales ip3
    oscZ4.setup("192.168.0.14", 9001);//zonales ip4
    
//--Presencias Controls Setup
    z1 = false;
    z2 = false;
    z3 = false;
    z4 = false;
    z5 = false;
    
//    contador = false;
    gui.setup("OSC-sender");
    gui.add(endTime.set("end time", 1000, 1, 6000));
    gui.add(fadeIn.set("fadeIn", 0, 110, 255));
    gui.add(fadeOut.set("fadeout", 255, 0, 255));
    
    timerEnd = false;
    startTime =ofGetElapsedTimeMillis();}
//-------------------------------------------------------------

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    menu.draw();
    gui.draw();
    float barWidth = 600;
    int timer = ofGetElapsedTimeMillis()-startTime;
    
    
    if (timer>=endTime) {
        timerEnd = true;
    }
    //
    float timeBar = ofMap(timer, 0.0, endTime, 0.0, 1.0,true);
    ofSetColor(0,0,0,fadeIn*timeBar);
    ofRect(ofGetWidth()/2-300, ofGetHeight()/2, barWidth*timeBar, 30);
    
    if (fadeIn <255) {
        fadeIn++;
        //cout<<fadeIn<<endl;
    }
    if (fadeOut <= 255 && fadeOut >0) {
        fadeOut--;
        //cout<<fadeOut<<endl;
    }
}
//--------------------------------------------------------------
void ofApp::fadeInCh1(){ //fade in channel 1
    ofxOscMessage(m);
    m.setAddress("/ch1/fade_in");
    m.addIntArg(1000);
    oscSender.sendMessage(m);
    
}
//--------------------------------------------------------------
void ofApp::fadeInCh2(){ //fade in channel 2
    ofxOscMessage(m);
    m.setAddress("/ch2/fade_in");
    m.addIntArg(1000);
    oscSender.sendMessage(m);
}
//--------------------------------------------------------------
void ofApp::fadeOutCh1(){//fade out ch 1

    ofxOscMessage(m);
    m.setAddress("/ch1/fade_in");
    m.addIntArg(1000);
    oscSender.sendMessage(m);
}
//--------------------------------------------------------------
void ofApp::fadeOutCh2(){ //fade out ch 2
    ofxOscMessage(m);
    m.setAddress("/ch2/fade_out");
    m.addIntArg(1000);
    oscSender.sendMessage(m);
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
//-----Teclas ZOnales      -----------------------
//---------------------------------------------------------
//ZONA 1
    //Presencia en Z1
    if (key == '1') {
        z1==true;
        ofxOscMessage m;
        m.setAddress("/ch2/pause");
        oscZ1.sendMessage(m);
        //take a pause
        ofSleepMillis(1000);
        m.setAddress("/ch1/play");
        oscZ1.sendMessage(m);
        
        m.setAddress("/ch1/fade_in");
        m.addIntArg(1000);
        oscZ1.sendMessage(m);
        ofLogNotice("alguien zona 1");
    }
    //Ausencia en z1
    if (key == 'q') {
        z1=false;
        ofxOscMessage m;
        m.setAddress("/ch1/pause");
        oscZ1.sendMessage(m);
        //take a pause
        ofSleepMillis(1000);
        m.setAddress("/ch2/play");
        oscZ1.sendMessage(m);
        
        m.setAddress("/ch1/fade_out");
        m.addIntArg(1000);
        oscZ1.sendMessage(m);
        ofLogNotice("nadie zona 1");
        
    }
//ZONA 2
    //Presencia en z2 :
    if (key == '2') {
        z2=true;
        ofxOscMessage m;
        m.setAddress("/ch2/pause");
        oscZ2.sendMessage(m);
        //take a pause
        ofSleepMillis(1000);
        m.setAddress("/ch1/play");
        oscZ2.sendMessage(m);
        
        m.setAddress("/ch1/fade_in");
        m.addIntArg(5000);
        oscZ2.sendMessage(m);
        ofLogNotice("alguien zona 2");
    }
    //Ausencia en z2:
    if (key == 'w') {
        z2=false;
        ofxOscMessage m;
        m.setAddress("/ch1/pause");
        oscZ2.sendMessage(m);
        //take a pause
        ofSleepMillis(1000);
        m.setAddress("/ch2/play");
        oscZ2.sendMessage(m);
        
        m.setAddress("/ch1/fade_out");
        m.addIntArg(500);
        oscZ2.sendMessage(m);
        ofLogNotice("nadie zona 2");
    }
//ZONA 3
    //Presencia en z3:
    if (key == '3') {
        z3=true;
        ofxOscMessage m;
        m.setAddress("/ch2/stop");
        oscZ3.sendMessage(m);
        //take a pause
        ofSleepMillis(1000);
        m.setAddress("/ch1/fade_in");
        //aauqi estoyyy
        m.addIntArg(500);
        oscZ3.sendMessage(m);
        
        m.setAddress("/ch1/play");
        oscZ3.sendMessage(m);
        ofLogNotice("alguien zona 3");
    }
    //Ausencia en z3:
    
    if (key == 'e') {
        z3 =false;
        ofxOscMessage m;
        m.setAddress("/ch1/pause");
        oscZ3.sendMessage(m);
        //take a pause
        ofSleepMillis(1000);
        m.setAddress("/ch2/play");
        oscSender.sendMessage(m);
        
        m.setAddress("/ch1/fade_out");
        m.addIntArg(1000);
        oscZ3.sendMessage(m);
        ofLogNotice("nadie zona 3");
    }
//ZONA 4
    //Presencia en z4:
    if (key == '4') {
        z4 = true;
        ofxOscMessage m;
        m.setAddress("/ch2/pause");
        oscZ4.sendMessage(m);
        //take a pause
        ofSleepMillis(1000);
        m.setAddress("/ch1/play");
        oscZ4.sendMessage(m);
        
        m.setAddress("/ch1/fade_in");
        m.addIntArg(500);
        oscZ4.sendMessage(m);
        ofLogNotice("alguien zona 4");
    }
    //Ausencia en z4 :
    if (key == 'r') {
        z4 =false;
        ofxOscMessage m;
        m.setAddress("/ch1/pause");
        oscZ4.sendMessage(m);
        //take a pause
        ofSleepMillis(1000);
        m.setAddress("/ch2/play");
        oscZ4.sendMessage(m);
        
        m.setAddress("/ch1/fade_out");
        m.addIntArg(500);
        oscZ4.sendMessage(m);
        ofLogNotice("nadie zona 4");
    }
//ZONA 5  :
    //presendia zona 5
    if (key=='5') {
        z5=true;
        ofxOscMessage m;
        m.setAddress("/ch1/set_media");
        m.addIntArg(1);
        oscSender.sendMessage(m);
        
        ofLogNotice("alguien zona 5");
        
        ofSleepMillis(2000);
        
        fadeInCh1();
    }
    //Ausencia en z5 :
    if (key=='t') {
        
        ofxOscMessage(m);
        m.setAddress("/ch1/fade_out");
        m.addIntArg(1000);
        oscSender.sendMessage(m);
        
        ofSleepMillis(1000);
        //inicio();
        
//        m.setAddress("/ch1/set_media");
//        m.addIntArg(3);
//        oscSender.sendMessage(m);
        
        ofLogNotice("nadie zona 5");
    }

    
// Teclas Generales
//--------------------------------------------------------------

    if (key == 'g') {
        ofxOscMessage m;
        m.setAddress("/toggle_display");
        oscSender.sendMessage(m);
        ofLogNotice("GUI");
    }
    if (key == 'o') {
        inicio();
        stepUno();
        fadeInCh2();
        ofLogWarning("inicio");
    }
    if (key == 'k') {
        killAll();
        ofxOscMessage m;
        m.setAddress("/ch1/set_alpha");
        m.addIntArg(0);
        oscSender.sendMessage(m);
        ofLogWarning("Reset -all Systems GO!!!");
    }
    if (key =='a') {
        ofxOscMessage m;
        m.setAddress("/ch1/fade_in");
        m.addIntArg(1000);
        oscSender.sendMessage(m);

    }
    
    if (key =='s') {
        ofxOscMessage m;
        m.setAddress("/ch2/fade_in");
        m.addIntArg(1000);
        oscSender.sendMessage(m);
        ofLogNotice("ch2 fade in ch2");
    }
    
    if (key =='d') {
        ofxOscMessage m;
        m.setAddress("/ch1/fade_out");
        m.addIntArg(1000);
        oscSender.sendMessage(m);
        ofLogNotice(" ch1 fade out!!");
    }
    
    if (key =='f') {
        ofxOscMessage m;
        m.setAddress("/ch2/fade_out");
        m.addIntArg(1000);
        oscSender.sendMessage(m);
        ofLogNotice(" ch2 fade out!!");
    }
    if (key =='h') {
        ofxOscMessage m;
        m.setAddress("/ch1/stop");
        oscSender.sendMessage(m);
        ofLogNotice(" ch1 stop!!!");
    }
    if (key =='j') {
        ofxOscMessage m;
        m.setAddress("/ch2/stop");
        oscSender.sendMessage(m);
        ofLogNotice(" ch2 stop!!!");
    }
    
    if (key =='0') {
        ofxOscMessage m;
        m.setAddress("/ch2/set_top_frame");
        m.addIntArg(1);
        oscSender.sendMessage(m);
    }
    if (key =='9') {
        ofxOscMessage m;
        m.setAddress("/ch1/set_top_frame");
        m.addIntArg(2);
        oscSender.sendMessage(m);
    }
//--------------------------------------------------------------
}


//-------------------General funcions
//--------------------------------------------------------------
void ofApp::inicio(){
    ofxOscMessage(m);
    m.setAddress("/ch1/set_media");
    m.addIntArg(3);
    oscSender.sendMessage(m);
    ofLogNotice("set Media ch1");
}
//--------------------------------------------------------------
void ofApp::stepUno(){
    ofxOscMessage(m);
    m.setAddress("/ch2/set_media");
    m.addIntArg(2);
    oscSender.sendMessage(m);
    ofLogNotice("set media ch2");
    //play  ch 2
    m.setAddress("/ch2/play");
    oscSender.sendMessage(m);
}
//--------------------------------------------------------------
void ofApp::killAll(){
    ofxOscMessage(m);
    m.setAddress("/ch1/stop");
    oscSender.sendMessage(m);
    
    m.setAddress("/ch2/set_alpha");
    m.addIntArg(0);
    oscSender.sendMessage(m);
    
    m.setAddress("/ch2/stop");
    oscSender.sendMessage(m);
}
//--------------------------------------------------------------
void ofApp:: controlZonas(){
    if (z5 == true) {
        if (z1 == true && z5 == true) {
            ofxOscMessage(m);
            
            m.setAddress("/ch2/set_alpha");
            m.addIntArg(0);
            oscZ1.sendMessage(m);
            
            m.setAddress("/ch1/set_top_frame");
            m.addIntArg(2);
            oscZ1.sendMessage(m);
            
            m.setAddress("/ch2/set_media");
            m.addIntArg(3);
            oscZ1.sendMessage(m);

            ofLogNotice("Zona 5 y Zona 1");
            
            fadeInCh2();
            
            ofSleepMillis(1000);
            
            m.setAddress("/ch1/fade_out");
            m.addIntArg(1000);
            oscZ1.sendMessage(m);
            
            fadeOutCh1();
            ofLogNotice("complete caras z1 y z5 ");

        }
        if (z2 == true && z5 == true) {
            ofxOscMessage(m);
            m.setAddress("/ch2/set_alpha");
            m.addIntArg(0);
            oscZ2.sendMessage(m);
            
            m.setAddress("/ch2/set_top_frame");
            m.addIntArg(1);
            oscZ2.sendMessage(m);
            
            m.setAddress("/ch2/set_media");
            m.addIntArg(3);
            oscZ2.sendMessage(m);
            fadeInCh2();
            
            ofSleepMillis(5000);
            fadeOutCh1();
            
            m.setAddress("/ch1/set_top_frame");
            m.addIntArg(2);
            oscZ2.sendMessage(m);


        }
        if (z3 == true && z5 == true) {
            ofLogNotice("Zona 5 y Zona 3");
            
            ofxOscMessage(m);
            m.setAddress("/ch2/set_alpha");
            m.addIntArg(0);
            oscZ3.sendMessage(m);
            
            m.setAddress("/ch2/set_top_frame");
            m.addIntArg(1);
            oscZ3.sendMessage(m);
            
            m.setAddress("/ch2/set_media");
            m.addIntArg(3);
            oscZ3.sendMessage(m);
            fadeInCh2();
            
            ofSleepMillis(5000);
            fadeOutCh1();
            
            m.setAddress("/ch1/set_top_frame");
            m.addIntArg(2);
            oscZ3.sendMessage(m);
            
        }
        if (z4 == true && z5 == true) {
            ofLogNotice("Zona 5 y Zona 4");
            ofxOscMessage(m);
            m.setAddress("/ch2/set_alpha");
            m.addIntArg(0);
            oscZ4.sendMessage(m);
            

            
            m.setAddress("/ch2/set_media");
            m.addIntArg(1);
            oscZ4.sendMessage(m);
            
            m.setAddress("/ch2/set_top_frame");
            m.addIntArg(1);
            oscZ4.sendMessage(m);
            
            fadeInCh2();
            
            ofSleepMillis(1000);
            fadeOutCh1();
            

        }
    }
}
