#pragma once

class Node {
public:
	// Declare variables
	int data;
	Node* next;

	// Constructor to initialize the data and next pointer
	Node(int value) {
		data = value;
		next = nullptr;
	};
};

// I asked AI where to start and to help me break it down into smaller steps. (I am starting with this file, but this remains true for the rest.)
// It said that best practices were to seperate classes into header files,
// and later include them in the cpp files.
