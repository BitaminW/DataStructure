#include <iostream>
#include <cstdlib>

typedef int ElementType;

struct Node {
	ElementType Data;
	Node* next_node;
};

/*        Create Node           */
Node* SLL_CreateNode(ElementType new_data) {
	Node* new_node = new Node();

	new_node->Data = new_data;
	new_node->next_node = NULL;

	return new_node;
}

// Remove node from memory
void SLL_DestroyNode(Node* node) {
	delete node;
}

// 
void SLL_AppendNode(Node** head, Node* new_node) {

	// if the head node is NULL, the new node is head
	if ((*head) == NULL) {
		*head = new_node;
	}
	else {
		// Find the tail and connect the new_node

		Node* tail = (*head);
		while (tail->next_node != NULL) {
			tail = tail->next_node;
		}
		tail->next_node = new_node;
	}
}

// inserting node
void SLL_InsertAfter(Node* current, Node* new_node) {
	new_node->next_node = current->next_node;
	current->next_node = new_node;

}

void SLL_InsertNewHead(Node** head, Node* new_head) {
	if (*head == NULL) {
		*head = new_head;
	}
	else {
		new_head->next_node = *head;
		*head = new_head;
	}
}

// Remove the node
void SLL_RemoveNode(Node** head, Node* remove) {
	if (*head == remove) {
		*head = remove->next_node;
	}
	else {
		Node* current = *head;
		while (current != NULL && current->next_node != remove) {
			current = current->next_node;
		}
		if (current != NULL) {
			current->next_node = remove->next_node;
		}
	}
}

// Explore the node
Node* SLL_GetNodeAt(Node* head, int Location) {
	Node* current = head;

	while (current != NULL && (--Location) >= 0) {
		current = current->next_node;
	}

	return current;
}

// Count the number of nodes
int SLL_GetNodeCount(Node* head) {
	int count = 0;
	Node* current = head;

	while (current != NULL) {
		current = current->next_node;
		count++;
	}

	return count;
}
