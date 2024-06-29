#include<stdio.h> 
#include<stdlib.h> 

struct Node 
{ 
	int data; 
	struct Node* next; 
}; 

void push(struct Node** head_ref, int new_data) 
{ 
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
	new_node->data = new_data; 
	new_node->next = (*head_ref); 
	(*head_ref) = new_node; 
} 

void deleteNode(struct Node** head_ref, int key) 
{ 
	struct Node* temp = *head_ref; 
	struct Node* prev = NULL; 
	if (temp != NULL && temp->data == key) 
	{ 
		*head_ref = temp->next; 
		free(temp); 
		return; 
	} 
	while (temp != NULL && temp->data != key) 
	{ 
		prev = temp; 
		temp = temp->next; 
	} 
	if (temp == NULL) return; 

	prev->next = temp->next; 

	free(temp); 
} 

int getCount(struct Node* head) 
{ 
	if (head == NULL) 
		return 0; 
	return 1 + getCount(head->next); 
} 

int main() 
{ 
	struct Node* head = NULL; 

	push(&head, 1); 
	push(&head, 3); 
	push(&head, 1); 
	push(&head, 2); 
	push(&head, 1); 
	push(&head, 3); 
	push(&head, 1); 
	push(&head, 2); 
	push(&head, 1); 

	printf("Count of nodes before deletion is %d\n", getCount(head)); 
	
	deleteNode(&head, 3);
	deleteNode(&head, 2);
	deleteNode(&head, 1);
	
	printf("Count of nodes after deletion is %d\n", getCount(head)); 
	
	return 0; 
}
