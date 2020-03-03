#include "ofApp2.h"

//--------------------------------------------------------------
void ofApp2::setup(){
// lighting
	ofSetSmoothLighting(true);
	pointLight.setDiffuseColor( ofFloatColor(.85, .85, .55) );
	pointLight.setSpecularColor( ofFloatColor(1.f, 1.f, 1.f));
// shapes
	float width	 = ofGetWidth() * .12;
	float height = ofGetHeight() * .12;
    cylinder.setPosition(ofGetWidth()*0.5,ofGetHeight()*0.5,0);
	cylinder.set(width*.7, height*.5);
    box.set(width*0.2,width*0.4,width*0.6);
    box.setPosition(ofGetWidth()*0.75,ofGetHeight()*0.5,0);
    clock.setPosition(ofGetWidth()*0.5,ofGetHeight()*0.25,0);
    ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp2::update() {
}

//--------------------------------------------------------------
void ofApp2::draw() {
	float spinX = ofGetElapsedTimeMillis() * 1e-3 * 360 * 0.1;
	pointLight.enable();
    ofSetColor(0,255,0);
    ofFill();
    //cylinder.rotateDeg(1,1,0,0);
    //box.rotate(1,0,1,0);
    ofRotateDeg(spinX,0,1,0);
    //box.orbitAroundDeg(
    //    1,
    //    (glm::vec3){0,1,0},
    //    (glm::vec3){ofGetWidth()*0.5,ofGetWidth()*0.5,0});
    box.draw();
    //cylinder.draw();
    clock.draw();
}
