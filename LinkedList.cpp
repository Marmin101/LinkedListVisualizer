#include "LinkedList.h"
#include <iostream>
#include <cstdlib>

// Function to add a node to the linked list
void LinkedList::insertAtHead(int value) {
	Node* newNode = new Node(value);

	if (head == nullptr) { // If the list is empty make the new node the head
		head = newNode;
	}
	else { // If the list is not empty, make the new node the head and point it to the old head
		newNode->next = head;
		head = newNode;
	}
}

// Function to add a node to the end (tail) of the linked list
void LinkedList::insertAtTail(int value) {
	Node* newNode = new Node(value);

	if (head == nullptr) { // If the list is empty make the new node the head
		head = newNode;
	}
	else { // If the list is not empty, traverse the list to find the last node
		Node* temp = head; // Temp pointer to traverse list

		while (temp->next != nullptr) {
			temp = temp->next;
		}

		// Set the next pointer of the last node to the new node
		temp->next = newNode; // This is the new tail
	}
}

// Function to delete the head node of the linked list
void LinkedList::deleteHead() {
	if (head == nullptr) {
		return; // List is empty
	}
	Node* temp = head; // Temp pointer to store the head node
	head = head->next; // Move the head pointer to the next node
	delete temp; // Delete the old head node
}

// Function to delete the last (tail) node of the linked list
void LinkedList::deleteTail() {
	if (head == nullptr) {
		return; // List is empty
	}
	if (head->next == nullptr) { // If there is only one node in the list
		delete head;
		head = nullptr;
		return;
	}

	Node* temp = head; // Temp pointer to traverse the list

	while (temp->next->next != nullptr) { // Traverse the list until the second last node
		temp = temp->next; // Move the temp pointer to the next node
	}

	delete temp->next; // Delete the last node
	temp->next = nullptr; // Set the next pointer of the second last node to nullptr

	// All in all, the last node is deleted and the second last node becomes the new tail
}

// Function to print the linked list (for debugging)
void LinkedList::printList() {
	Node* temp = head; // Temp pointer to traverse the list

	while (temp != nullptr) { // Traverse the list until the end
		std::cout << temp->data << " -> "; // Print the data of the current node and an arrow
		temp = temp->next; // Move the temp pointer to the next node
	}
	std::cout << "nullptr" << std::endl; // Print nullptr at the end of the list
}

// I used AI to help me break down what I needed to do to implement the linked list into smaller steps.
// With its explanations, I added a million comments to help me understand what I was doing.