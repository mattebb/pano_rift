#pragma once

#include "ofMain.h"
#include "ofxOculusDK2.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

        void reloadShader();
        void drawScene(int eye);
    
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
        ofxOculusDK2		oculusRift;
        ofEasyCam			cam;
    
        ofShader            panoshader;
        ofImage             panoLeft;
        ofImage             panoRight;
};
