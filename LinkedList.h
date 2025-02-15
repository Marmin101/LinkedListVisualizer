#pragma once
#include "Node.h"

class LinkedList {
public:
	// Declare variables
	Node* head; // Pointer to the head of the linked list

	// Constructor to initialize the head pointer
	LinkedList() {
		head = nullptr; // Initialize head to null
	};

	// Functions to add a node to the linked list (the functions are defined in the cpp file)
	void insertAtHead(int value);
	void insertAtTail(int value);
	void deleteHead();
	void deleteTail();
	void printList(); // To debug
};
