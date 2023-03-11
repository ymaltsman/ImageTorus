#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofBackground(0);
	glEnable(GL_DEPTH_TEST);
	
	W = 200; //doesn't seem to be able to handle large images
	H = 200; 
	img.load("ocean.jpg");
	img.resize(W, H);
	src = img.getPixels().getData();
}

//--------------------------------------------------------------
void ofApp::update() {
}

//--------------------------------------------------------------
void ofApp::draw() {
	imgtorus();
	vbo.draw(GL_LINE_LOOP, 0, W * H);
	//img.draw(600, 600);
}

void ofApp::imgtorus() {
	int r = 0;
	int g = 0;
	int b = 0;
	for (float theta = 0; theta < TWO_PI; theta += TWO_PI / W) {
		for (float phi = 0; phi < TWO_PI; phi += TWO_PI / H) {
			float x = (c + a * cos(theta)) * cos(phi);
			float y = (c + a * cos(theta)) * sin(phi);
			float z = a * sin(theta);
			int idx = 3 * (phi * (H / TWO_PI) * W + theta * (W / TWO_PI));
			r = src[idx];
			g = src[idx + 1];
			b = src[idx + 2];
			ofColor col(r, g, b);
			mesh.addColor(col);
			mesh.addVertex(ofVec3f(300 + x, 300 + y, 100 + z));
		}
	}
	vbo.setMesh(mesh, GL_DYNAMIC_DRAW);
}