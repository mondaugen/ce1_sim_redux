#ifndef CE1_CLOCK_H
#define CE1_CLOCK_H 

#include <math.h>
#include "ofMain.h"

#define BODY_COLOR 0x00ff00
#define HAND_COLOR 0xff0000
#define HOUR_LEN_SCALE .7
#define MIN_LEN_SCALE .8
#define HAND_THICK_SCALE 5e-2

class ce1_clock {
    ofCylinderPrimitive body;
    ofBoxPrimitive hour_hand;
    ofBoxPrimitive minute_hand;
    ofBoxPrimitive second_hand;
    float x;
    float y;
    float z;
    float _size;
public:
    ce1_clock(float size=100)
    {
        _size=size;
        body.set(_size,_size*.1);
        body.setResolution(20,13,4);
        hour_hand.set(_size*HOUR_LEN_SCALE,_size*1e-2,_size*9e-2);
        minute_hand.set(_size*MIN_LEN_SCALE,_size*1e-2,_size*6e-2);
    }
    void setPosition(float x_, float y_, float z_)
    {
        x=x_;
        y=y_;
        z=z_;
    }
    void draw(void)
    {
        float spinX = ofGetElapsedTimeMillis() * 1e-3 * 360 * 0.1;
        //ofEnableAlphaBlending();
        ofTranslate(x,y,z);
        ofRotateDeg(90,1,0,0);

        // draw hour hand
        ofPushMatrix();
        ofRotateDeg(spinX/3600,0,1,0);
        ofTranslate(_size*.5*HOUR_LEN_SCALE,_size*HAND_THICK_SCALE,0);
        ofSetHexColor(HAND_COLOR);
        ofFill();
        hour_hand.draw();
        ofPopMatrix();

        // draw minute hand
        ofPushMatrix();
        ofRotateDeg(spinX/60,0,1,0);
        ofTranslate(_size*.5*MIN_LEN_SCALE,_size*2*HAND_THICK_SCALE,0);
        ofSetHexColor(HAND_COLOR);
        ofFill();
        hour_hand.draw();
        ofPopMatrix();
        
        // draw body
        ofSetHexColor(BODY_COLOR);
        ofFill();
        body.draw();
    }
};
    
#endif /* CE1_CLOCK_H */
