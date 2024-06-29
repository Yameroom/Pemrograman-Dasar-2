#include <iostream>
#include <ctime>
using namespace std;

class Node 
{ 
public: 
	int key; 
	Node* next; 
}; 

void push(Node** head_ref, int new_key) 
{ 
	Node* new_node = new Node(); 
	new_node->key = new_key; 
	new_node->next = (*head_ref); 
	(*head_ref) = new_node; 
} 

bool searchIterative(Node* head, int x) 
{ 
	Node* current = head;  
	while (current != NULL) 
	{ 
		if (current->key == x) 
			return true; 
		current = current->next; 
	} 
	return false; 
} 

int main() 
{ 
	Node* head = NULL; 
	int x = 21; 
	push(&head, 10); 
	push(&head, 30); 
	push(&head, 11); 
	push(&head, 21); 
	push(&head, 14); 
	push(&head, 15);
	push(&head, 90);
	
	clock_t start, end;
	start = clock();

	for (int i = 0; i < 1000000; i++) {
		searchIterative(head, 90);
	}

	end = clock();

	double duration = double(end - start) / CLOCKS_PER_SEC * 1000;

	cout << "Waktu Iterative: " << duration << " milliseconds" << endl;

	return 0; 
}

