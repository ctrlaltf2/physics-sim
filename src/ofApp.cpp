#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetVerticalSync(true);

	mesh.setMode(OF_PRIMITIVE_POINTS);

	ofEnableDepthTest();
	glEnable(GL_POINT_SMOOTH); // use circular points instead of square points
	glPointSize(2);

	Particle electron(universeConstant::m_e, Vec3Physical(0, 0, 0), Vec3Physical(0, 127, 0));
	electron.charge(-1 * universeConstant::e);

    //Particle yeet(1, Vec3Physical(0, 0, 0), Vec3Physical(50, 0, 0));

    particleSystem.add(electron), mesh.addVertex(ofPoint(0, 0, 0));
}

//--------------------------------------------------------------
void ofApp::update() {
    particleSystem.update();
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofBackgroundGradient(ofColor::gray, ofColor::black, OF_GRADIENT_CIRCULAR);

	cam.begin();
	//ofScale(2, -2, 2); // flip the y axis and zoom in a bit
	//ofRotateYDeg(90);

	std::vector<ofVec3f> positions = particleSystem.positions();
	for(unsigned i = 0; i < positions.size(); ++i) {
        mesh.setVertex(i, positions[i]);
	}
	mesh.draw();
	cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
