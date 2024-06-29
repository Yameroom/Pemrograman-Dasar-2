#include <bits/stdc++.h> 
using namespace std; 

class Node 
{ 
	public: 
	int data; 
	Node *next; 
}; 

void push(Node** head_ref, int new_data) 
{ 

	Node* new_node = new Node(); 
	new_node->data = new_data; 
	new_node->next = (*head_ref); 
	(*head_ref) = new_node; 
} 

void insertAfter(Node* prev_node, int new_data) 
{ 
	if (prev_node == NULL) 
	{ 
	cout<<"the given previous node cannot be NULL"; 
	return; 
	} 
	Node* new_node = new Node(); 
	new_node->data = new_data; 
	new_node->next = prev_node->next; 
	prev_node->next = new_node; 
} 
void append(Node** head_ref, int new_data) 
{ 
	Node* new_node = new Node(); 
	Node *last = *head_ref; 
	new_node->data = new_data; 
	new_node->next = NULL; 
	if (*head_ref == NULL) 
	{ 
	*head_ref = new_node; 
	return; 
	} 
	while (last->next != NULL) 
	last = last->next; 
	last->next = new_node; 
return; 
} 
 
void printList(Node *node) 
{ 
	while (node != NULL) 
	{ 
	cout << " " << node->data << "(" << node << ")"; 
	node = node->next; 
	} 
} 

int main() 
{ 

	Node* head = NULL; 
	append(&head, 6); 
	push(&head, 7); 
	push(&head, 1); 
	push(&head, 9);
    push(&head, 10);
	append(&head, 4); 
	append(&head, 13);
    append(&head, 14);
	insertAfter(head->next, 8); 
	insertAfter(head->next, 11);
    insertAfter(head->next->next, 12);
	cout<<"Created Linked list is: "; 
	printList(head); 
return 0; 
}
