#include "ofApp.h"
#include <iostream>
#include <vector>

// Declare constants
float randomMin = 10; 
float randomMax = 100;
float distanceBetweenNodes = 200.0;

//--------------------------------------------------------------
void ofApp::setup(){
	// Initialization of variables and methods
	ofSetFrameRate(60); // For the animations
	ofSetBackgroundColor(240, 240); // Set the background color to off-white
	amplitude = 50.0f;
	time = 0.0f; // Initialize time to 0
	cameraX = 0.0f;

	// Load fonts with different sizes on launch (because openFrameworks for some reason doesn't let you set the size after...)
	for (int i = 10; i <= 100; i++) {
		ofTrueTypeFont fontArial;
		fontArial.load("arial", i);
		fontMap[i] = fontArial; // Store the font in the map
	}

	// Insert the starting head node to the linked list
	list.insertAtHead(ofRandom(randomMin, randomMax));
}

//--------------------------------------------------------------
void ofApp::update(){
	time += ofGetLastFrameTime(); // Update time with the time since the last frame
}

//--------------------------------------------------------------
void ofApp::draw(){
	// Apply camera translation
	ofPushMatrix();
	ofTranslate(cameraX, 0);

	// Initialize variables
	float x = 100.0f; // Start drawing at x = 100
	float y = ofGetHeight() / 2.0f; // Center the linked list on the y-axis

	// Draw the linked list
	Node* temp = list.head;
	while (temp != nullptr) { // (if the temp pointer is not null,)
		float nextX = x + distanceBetweenNodes; // Calculate the x position of the next node
		float nextY = y + amplitude * sin(time + (temp->next ? temp->next->data : 0)); // Calculate the y position of the next node (moves up and down with sine wave)

		if (temp->next != nullptr) { // (if the next node from the temp pointer is not null,)
			// Draw the line between current node and next node
			ofSetColor(50, 50, 50); // Dark grey
			ofDrawLine(x, y, nextX, nextY); // Draw the line
		}

		drawNode(temp, x, y); // Draw the node
		x = nextX; // Update x to next node's position
		y = nextY; // Update y to next node's position
		temp = temp->next; // Move to the next node
	}

	// Reset the camera translation
	ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key) {
	case 'q': // Add a node to the head of the linked list
		list.insertAtHead(ofRandom(randomMin, randomMax));
		break;
	case 'w': // Add a node to the tail of the linked list
		list.insertAtTail(ofRandom(randomMin, randomMax));
		break;
	case 'a': // Delete the head node of the linked list
		list.deleteHead();
		break;
	case 's': // Delete the tail node of the linked list
		list.deleteTail();
		break;
	case 'd': // Print the linked list to the console
		list.printList();
		break;
	case 'z': // Increase amplitude of the sine wave
		amplitude += 10.0f;
		break;
	case 'x': // Decrease amplitude of the sine wave
		amplitude -= 10.0f;
		break;
	case 'e': // Quick sort the linked list
		list.quickSort();
		break;
	case OF_KEY_LEFT: // Move the camera to the left
		cameraX += 10.0f;
		break;
	case OF_KEY_RIGHT: // Move the camera to the right
		cameraX -= 10.0f;
		break;
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

//--------------------------------------------------------------

// Custom function to draw nodes in the linked list
void ofApp::drawNode(Node* node, float x, float y) {
	std::string text = to_string(node->data);

	// Determine font size
	int fontSize = node->data;
	if (fontSize < randomMin) { // Ensuring font size is within bounds
		fontSize = randomMin;
	}
	else if (fontSize > randomMax) {
		fontSize = randomMax;
	}
	ofTrueTypeFont& fontArial = fontMap[fontSize]; // Get the font from the map created above

	ofRectangle bounds = fontArial.getStringBoundingBox(text, 0, 0);

	int boundsWidth = bounds.getWidth();
	int boundsHeight = bounds.getHeight();
	int centerX = x - boundsWidth / 2;
	int centerY = y + boundsHeight / 2;

	// Draw the node
	ofSetColor(50, 200, 50); // Green
	ofDrawCircle(x, y, node->data); // Draw the node (Radius is data of the node)

	// Write the text
	ofSetColor(255, 255, 255); // White
	fontArial.drawString(text, centerX, centerY);

	//ofDrawBitmapString(to_string(node->data), x - 10, y + 5); // Draw the size of the node
}
