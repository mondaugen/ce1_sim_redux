#pragma once

#include "ofMain.h"
#include "ce1_clock.h"

class ofApp2 : public ofBaseApp{

    ofCylinderPrimitive cylinder;
    ofBoxPrimitive box;
	ofLight pointLight;
    ce1_clock clock;
	
public:
	void setup();
	void update();
	void draw();
};
