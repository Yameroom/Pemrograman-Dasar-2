#include <iostream>
#include <ctime>
using namespace std;

struct Node 
{ 
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

bool searchRecursive(Node* head, int x) 
{ 
	if (head == NULL) 
		return false; 
	if (head->key == x) 
		return true; 
	return searchRecursive(head->next, x); 
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
	push(&head, 12); 
	push(&head, 85); 
	push(&head, 67); 
	
	clock_t start, end;
	start = clock();

	for (int i = 0; i < 1000000; i++) {
		searchRecursive(head, 27);
	}

	end = clock();

	double duration = double(end - start) / CLOCKS_PER_SEC * 1000;

	cout << "Waktu Recusive: " << duration << " milliseconds" << endl;

	return 0; 
}

