#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(25);
	ofSetWindowTitle("openframeworks");

	ofBackground(39);

	ofEnableDepthTest();
	ofSetLineWidth(3);
}

//--------------------------------------------------------------
void ofApp::update() {

	if (ofGetFrameNum() % 50 < 35) {
	
		this->noise_step += ofMap(ofGetFrameNum() % 50, 0, 35, 0.1, 0.002);
	}
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateY(ofGetFrameNum() * 1.44);

	int width = 350;
	int height = 350;
	int len = 30;
	ofColor color;
	for (int z = -600; z <= 600; z += 30) {

		color.setHsb(ofMap(z, -600, 600, 0, 255), 100, 255);

		ofPushMatrix();
		ofTranslate(0, 0, z);
		ofRotate(ofMap(ofNoise((z + 300) * 0.0008 + this->noise_step), 0, 1, -360, 360));

		ofFill();
		ofSetColor(39);

		
		ofBeginShape();

		ofVertex(glm::vec2(width * -1.5, height * -0.25));
		ofVertex(glm::vec2(width * 1.5, height * -0.25));
		ofVertex(glm::vec2(width * 1.5, height * 0.25));
		ofVertex(glm::vec2(width * -1.5, height * 0.25));

		ofEndShape(true);

		ofNoFill();
		ofSetColor(color);

		ofBeginShape();

		ofVertex(glm::vec2(width * -1.5, height * -0.25));
		ofVertex(glm::vec2(width * 1.5, height * -0.25));
		ofVertex(glm::vec2(width * 1.5, height * 0.25));
		ofVertex(glm::vec2(width * -1.5, height * 0.25));

		ofEndShape(true);

		ofPopMatrix();
	}

	this->cam.end();

	/*
	int start = 250;
	if (ofGetFrameNum() > start) {

		ostringstream os;
		os << setw(4) << setfill('0') << ofGetFrameNum() - start;
		ofImage image;
		image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		image.saveImage("image/cap/img_" + os.str() + ".jpg");
		if (ofGetFrameNum() - start >= 25 * 20) {

			std::exit(1);
		}
	}
	*/
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}