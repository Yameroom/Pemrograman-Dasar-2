#include <bits/stdc++.h> 
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

void deleteNode(Node** head_ref, int key) 
{ 
	Node* temp = *head_ref; 
	Node* prev = NULL; 

	if (temp != NULL && temp->data == key) 
	{ 
		*head_ref = temp->next; 
		delete temp; 
		return; 
	} 

	while (temp != NULL && temp->data != key) 
	{ 
		prev = temp; 
		temp = temp->next; 
	} 

	if (temp == NULL) return; 

	prev->next = temp->next; 

	delete temp; 
} 

int getCount(Node* head) 
{ 
	int count = 0; 
	Node* current = head; 
	while (current != NULL) 
	{ 
		count++; 
		current = current->next; 
	} 
	return count; 
} 

int main() 
{ 
	Node* head = NULL; 
	
	push(&head, 1); 
	push(&head, 3); 
	push(&head, 1); 
	push(&head, 2); 
	push(&head, 1); 
	push(&head, 1); 
	push(&head, 2); 
	push(&head, 1); 
	
	cout << "Count of nodes before deletion is " << getCount(head) << endl; 
	
	deleteNode(&head, 3);
	deleteNode(&head, 1);
	
	cout << "Count of nodes after deletion is " << getCount(head) << endl; 
	
	return 0; 
}

