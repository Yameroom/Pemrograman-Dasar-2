#include <iostream>
#include <cassert>

using namespace std;

class Node 
{ 
public: 
	int data; 
	Node* next; 
}; 

void push(Node** head_ref, int new_data) 
{ 
	Node* new_node = new Node(); 
	new_node->data = new_data; 
	new_node->next = (*head_ref); 
	(*head_ref) = new_node; 
} 

int GetNth(Node* head, int index) 
{ 
	Node* current = head; 
	int count = 0; 
	while (current != NULL) 
	{ 
		if (count == index) 
			return(current->data); 
		count++; 
		current = current->next; 
	} 
	assert(0);
} 

int main() 
{ 
	Node* head = NULL; 
	push(&head, 1); 
	push(&head, 4); 
	push(&head, 1); 
	push(&head, 12); 
	push(&head, 1); 
	push(&head, 2); 
	push(&head, 3); 
	push(&head, 9); 

	cout << "Element at index 0 is " << GetNth(head, 0); 

	return 0; 
}

