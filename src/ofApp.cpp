#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetLogLevel( OF_LOG_VERBOSE );
    ofSetVerticalSync( true );
    ofEnableDepthTest();
    
    oculusRift.baseCamera = &cam;
	oculusRift.setup();
    
    reloadShader();
    
    // rect textures are fine by default in GL3, we can just use GL_TEXTURE_2D.
    // disabling allows simpler normalized texture coordinates, not pixel coords
    ofDisableArbTex();
    
    panoLeft.loadImage("assem_interior_L.jpg");
    panoRight.loadImage("assem_interior_R.jpg");
    
    cam.setAutoDistance(false);
}

void ofApp::reloadShader() {
    panoshader.load("Shaders/pano.vert", "Shaders/pano.frag");
}

//--------------------------------------------------------------
void ofApp::update(){

}

void ofApp::drawScene(int eye) {
    panoshader.begin();
    if (eye == 0)
        panoshader.setUniformTexture("pano", panoRight.getTextureReference(), 1);
    else if (eye == 1)
        panoshader.setUniformTexture("pano", panoLeft.getTextureReference(), 1);
    
    ofDrawSphere(1000.0);
    
    panoshader.end();

}

//--------------------------------------------------------------
void ofApp::draw(){
    if(oculusRift.isSetup()){
		glEnable(GL_DEPTH_TEST);
        
		oculusRift.beginLeftEye();
		drawScene(0);
		oculusRift.endLeftEye();
		
		oculusRift.beginRightEye();
		drawScene(1);
		oculusRift.endRightEye();
		
		oculusRift.draw();
		
		glDisable(GL_DEPTH_TEST);
        
        //cam.end();
    }
	else{
		cam.begin();
		drawScene(0);
		cam.end();
	}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if( key == 'f' )
	{
		//gotta toggle full screen for it to be right
		ofToggleFullscreen();
	}
    if(key == 's'){
		reloadShader();
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
