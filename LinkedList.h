#pragma once
#include "Node.h"

class LinkedList {
public:
	// Declare variables
	Node* head;

	// Constructor to initialize the head pointer
	LinkedList() {
		head = nullptr;
	};

	// Functions to add a node to the linked list (the functions are defined in the cpp file)
	void insertAtHead(int value);
	void insertAtTail(int value);
	void deleteHead();
	void deleteTail();
	void printList(); // To debug
};
