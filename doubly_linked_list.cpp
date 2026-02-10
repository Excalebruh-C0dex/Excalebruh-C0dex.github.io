/**
* @author - Caleb Afenir
* @file doubly_linked_list.h -  This header file defines the methods which was declared in the doubly_linked_list.h file.
* 02/06/2026 - Caleb Afenir created file and added comments.
* 02/09/2026 - Caleb Afenir defined the methods in the doubly_linked_list.h file and added comments.
*/

#include "doubly_linked_list.h"
#include "milestone1.h"

DoublyLinkedList::DoublyLinkedList() :head(nullptr), tail(nullptr) {} // Constructor initializes an empty list with head and tail set to nullptr
DoublyLinkedList::~DoublyLinkedList() {
	clear(); //Delete all nodes to free memory
}
bool DoublyLinkedList::isEmpty() {
	return head == nullptr; // The list is empty if head is nullptr
}
void DoublyLinkedList::insertAtHead(int key) {
	DllNode* newNode = new DllNode(key); // Create a new node with the given key
	if (isEmpty()) { // If the list is empty, set both head and tail to
		head = newNode;
		tail = newNode;
	} else { // If the list is not empty, insert the new node at the head
		newNode->next = head; // Point the new node's next to the current head
		head->prev = newNode; // Point the current head's prev to the new node
		head = newNode; // Update head to the new node
	}
}
void DoublyLinkedList::insertAtTail(int key) {
	DllNode* newNode = new DllNode(key); // Create a new node with the given key
		if (isEmpty()) { // If the list is empty, set both head and tail to the new node
		head = newNode;
		tail = newNode;
	} else { // If the list is not empty, insert the new node at the tail
		newNode->prev = tail; // Point the new node's prev to the current tail
		tail->next = newNode; // Point the current tail's next to the new node
		tail = newNode; // Update tail to the new node
		}
}
void DoublyLinkedList::remove(int key) {
	DllNode* current = head; // Start from the head of the list
	while (current) { // Traverse the list to find the node with the given key
		if (current->key == key) { // If the node with the key is found
			if (current->prev) { // If it's not the head, update the previous node's next pointer
				current->prev->next = current->next; // Point the previous node's next to the current node's next
			}
			else { // If it is the head, update the head pointer
				head = current->next;
			}
			if (current->next) { // If it's not the tail, update the next node's prev pointer
				current->next->prev = current->prev; // Point the next node's prev to the current node's prev
			}
			else { // If it is the tail, update the tail pointer
				tail = current->prev;
			}
			delete current; // Delete the node to free memory
			return; // Exit after removing the node
		}
		current = current->next; // Move to the next node
	}
}
void DoublyLinkedList::removeHeaderNode() {
	DllNode* temp = head; // Store the current head node in a temporary variable
	if (head) { // If the list is not empty
		head = head->next; // Move the head pointer to the next node
		if (head) { // If the new head is not nullptr, update its prev pointer
			head->prev = nullptr; // Set the new head's prev to nullptr
		} else { // If the list becomes empty after removing the head, set tail to nullptr
			tail = nullptr;
		}
		delete temp; // Delete the old head node to free memory
	}
}
void DoublyLinkedList::removeTailNode() {
	DllNode* temp = tail; // Store the current tail node in a temporary variable
	if (tail) { // if the list is not empty
		tail = tail->prev; // Move the tail pointer to the previous node
		if (tail) { // if the new tail is not nullptr, update its next pointer
			tail->next = nullptr; // Set the new tail's next to nullptr
		} else {
			head = nullptr; // If the list becomes empty after removing the tail, set head to nullptr
		}
		delete temp; // Delete the old tail node to free memory
	}
}
void DoublyLinkedList::moveNodeToHead(int key) {
	DllNode* current = head; // Start from the head of the list
	while (current) { // Traverse the list to find the node with the give keyr
		if (current->key == key) { // If the node with the key is foundht 
			if (current == head) { // If the node is already the head, no need to move
				return;
			}
			// Remove the node from its current position
			if (current->prev) { // If it's not the head, update the previous node's next pointer
				current->prev->next = current->next; // Point the previous node's next to the current node's next
			}
			if (current->next) { // If it's not the tail, update the next node's prev pointer
				current->next->prev = current->prev; // Point the next node's prev to the current node's prev
			}
			if (current == tail) { // If the node is the tail, update the tail pointer
				tail = current->prev;
			}
			// Insert the node at the head
			current->prev = nullptr; // Set the current node's prev to nullptr
			current->next = head; // Point the current node's next to the current head
			if (head) { // If the list is not empty, update the current head's prev pointer
				head->prev = current; // Point the current head's prev to the current node
			}
			head = current; // Update head to the current node
			return; // Exit after moving the node
		}
		current = current->next; // Move to the next node
	}
}
void DoublyLinkedList::moveNodeToTail(int key) {
	DllNode* current = head; // Start from the head of the list
	while (current) { // Traverse the list to find the node with the given key
		if (current->key == key) { // If the node with the key is found
			if (current == tail) { // If the node is already the tail, no need to move
				return;
			}
			// Remove the node from its current position
			if (current->prev) { // If it's not the head, update the previous node's next pointer
				current->prev->next = current->next; // Point the previous node's next to the current node's next
			}
			if (current->next) { // If it's not the tail, update the next node's prev pointer
				current->next->prev = current->prev; // Point the next node's prev to the current node's prev
			}
			if (current == head) { // If the node is the head, update the head pointer
				head = current->next;
			}
			// Insert the node at the tail
			current->next = nullptr; // Set the current node's next to nullptr
			current->prev = tail; // Point the current node's prev to the current tail
			if (tail) { // If the list is not empty, update the current tail's next pointer
				tail->next = current; // Point the current tail's next to the current node
			}
			tail = current; // Update tail to the current node
			return; // Exit after moving the node
		}
		current = current->next; // Move to the next node
	}
}
void DoublyLinkedList::clear() {
	DllNode* current = head;
	while (current) {
		DllNode* nextNode = current->next; // Store the next node before deleting the current node
		delete current; // Delete the current node
		current = nextNode; // Moce to the next node
	}
	head = nullptr; // Reset head to nullptr 
	tail = nullptr; // Reset tail to nullptr
}
void DoublyLinkedList::printList() {
	DllNode* current = head; // Start from the head of the list
	std::string listStr = "Here are the list contents: "; // Initialize a string to build the list representation
	while (current) { // Traverse the list and append each node's key to the string
		listStr += std::to_string(current->key) + " ";
		current = current->next;
	}
	listStr += "End of List \n\n"; // Append a marker to indicate the end of the list
	logToFileAndConsole(listStr); // Log the list to both the console and the output file
}
void DoublyLinkedList::reversePrintList() {
	DllNode* current = tail; // Start from the tail of the list
	std::string listStr = "Here are the list contents reversed: "; // Initialize a string to build the reversed list representation
	while (current) { // Traverse the list in reverse and append each node's key to the string
		listStr += std::to_string(current->key) + " ";
		current = current->prev;
	}
	listStr += "End of List \n\n"; // Append a marker to indicate the end of the list
	logToFileAndConsole(listStr); // Log the reversed list to both the console and the output file
}

