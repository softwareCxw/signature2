#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	_f.setup();
}

//--------------------------------------------------------------
void ofApp::update(){
	_f.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	_f.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch(key)
	{
	case OF_KEY_F1 :
		ofSetFullscreen(true);
		break;
	case OF_KEY_F2 :
		ofSetFullscreen(false);
		break;
	case OF_KEY_F3 :
		ofShowCursor();
		break;
	case OF_KEY_F4 :
		ofHideCursor();
		break;
	default:
		break;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	_f.mouseTrigger(MOUSE_MOVED, x, y, 0);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	_f.mouseTrigger(MOUSE_DRAGGED, x, y, button);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	_f.mouseTrigger(MOUSE_PRESSED, x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	_f.mouseTrigger(MOUSE_RELEASED, x, y, button);
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
