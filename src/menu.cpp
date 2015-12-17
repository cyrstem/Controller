//
//  menu.cpp
//  Controller2
//
//  Created by Jacobo Heredia on 12/15/15.
//
//

#include "menu.h"

void menu::setup(){
     font.loadFont("SauceLight.otf", 12);
}

void menu::draw(){
    // Display Instructions-------------
    ofNoFill();
    ofRect(5, 5, 300, 500);
    ofSetColor(ofColor::green);
    font.drawString("---Teclas Generales---",10, 25);
    ofSetColor(ofColor::white);
    font.drawString("'g' para GUI",10, 50);
    font.drawString("'s' para fade-IN ch2", 10, 75);
    font.drawString("'d' para fade-OUT ch1", 10, 100);
    font.drawString("'f' para fade-OUT ch2", 10, 125);
    font.drawString("'h' para stop ch1", 10, 150);
    font.drawString("'j' para stop ch2", 10, 175);
    ofNoFill();
    ofRect(330, 5, 300, 300);
    ofSetColor(ofColor::green);
    font.drawString("---Zonales---",350,25);
    ofSetColor(ofColor::white);
    font.drawString("Presencia pi-11  '1' ",350, 50);
    font.drawString("Ausencia  pi-11  'q' ",350, 75);
    font.drawString("Presencia pi-12  '2' ",350, 100);
    font.drawString("Ausencia  pi-12  'w' ",350, 125);
    font.drawString("Presencia pi-13  '3' ",350, 150);
    font.drawString("Ausencia  pi-13  'e' ",350, 175);
    font.drawString("Presencia pi-14  '4' ",350, 200);
    font.drawString("Ausencia  pi-14  'r' ",350, 225);
    ofNoFill();
    ofRect(330, 400, 300, 100);
    ofSetColor(ofColor::green);
    font.drawString("---Main Control---",340,425);
    ofSetColor(ofColor::white);
    font.drawString("Para INIT  'o' ", 340,450);
    font.drawString("Para RESET 'k' ", 340,475);
    
}