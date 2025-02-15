#pragma once

#include "ofMain.h";
#include "LinkedList.h";

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		// LinkedList.h declarations
		LinkedList list;
		float amplitude;
		float time;

		void drawNode(Node* node, float x, float y); // Function to draw the linked list, intakes the node to draw and the x and y coordinates to draw it at

		std::map<int, ofTrueTypeFont> fontMap; // Create map to store fonts with sizes
};
