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

// Partition function for quick sort
Node* LinkedList::partition(Node* first, Node* last) {
	int pivot = last->data; // Choose the last element as the pivot
	Node* current = first; // Pointer to traverse the list.
	Node* pivotTracker = first; // Pointer to keep track of the pivot to swap with the last element if the last element is smaller than the pivot.
	
	std::cout << "Partitioning with pivot: " << pivot << std::endl;

	while (current != last) { // Traverse the list until the last element
		if (current != nullptr && current->data < pivot) { // If the current node is less than the pivot,
			std::swap(current->data, pivotTracker->data); // Swap the data of the current node and the node pointed by j
			pivotTracker = pivotTracker->next; // Move the pivotTracker pointer to the next node. HOW THE ? WORKS: What's left of the ?: if it's true, it's set to what's left of the :. If it's false, it's set to what's right of the :. 
			
			std::cout << "Swapping " << current->data << " and " << pivotTracker->data << std::endl;
		}
		current = current->next; // Move the i pointer to the next node
	}
	std::swap(pivotTracker->data, last->data); // Swap the data of the pivot and the node pointed by j
	
	std::cout << "Swapping pivot " << pivotTracker->data << " and " << last->data << std::endl;
	
	return pivotTracker; // Return the pivot to divide the list into two parts, used in the quickSortRecursive function
}

// Recursive function for quick sort
void LinkedList::quickSortRecursive(Node* first, Node* last) {
	if (first == nullptr || first == last || first->next == nullptr) { // If the first pointer is null, or the first and last pointers are the same, or if there is only one element in the list,
		return;
	}
	Node* pivot = partition(first, last); // Get the pivot found by the partition function
	
	std::cout << "Pivot found: " << pivot->data << std::endl;

	if (pivot != first) {
		Node* temp = first; // Temp pointer to traverse the list
		while (temp != nullptr && temp->next != pivot) { // While the pointer is not at the pivot and not null,
			temp = temp->next; // Move the temp pointer to the next node (until it reaches the pivot)
		}
		quickSortRecursive(first, temp); // Recursively call this function with the first and temp pointers
	}

	quickSortRecursive(pivot->next, last); // Recursively call this function with the next of the pivot and last pointers
}

// Quick sort function
void LinkedList::quickSort() {
	// Find the last node
	Node* last = head;
	while (last != nullptr && last->next != nullptr) { // Traverse the list until the last node that has a next pointer
		last = last->next; // Move the "last" pointer to the next node, until it reaches the truly last node
	}
	// Call the recursive quick sort function
	quickSortRecursive(head, last);
}

// I used AI to help me break down what I needed to do to implement the linked list into smaller steps.
// With its explanations, I added a million comments to help me understand what I was doing.