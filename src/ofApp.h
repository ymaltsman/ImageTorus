#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {

	public:
		void setup();
		void update();
		void draw();

		void imgtorus();

	ofVbo vbo;
	ofMesh mesh;
	float c = 100;//radius of hole
	float a = 50;//radius of tube
	int H, W;
	ofImage img;
	unsigned char* src;

};
