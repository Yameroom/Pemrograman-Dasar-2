#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node {
    int data;
    struct Node *next;
};

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void deleteNode(struct Node **head_ref, int position) {
    if (*head_ref == NULL)
        return;
    struct Node* temp = *head_ref;
    if (position == 0) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    for (int i = 0; temp != NULL && i < position - 1; i++)
        temp = temp->next;
    if (temp == NULL || temp->next == NULL)
        return;
    struct Node *next = temp->next->next;

    free(temp->next);
    temp->next = next;
}

void printList(struct Node *node) {
    while (node != NULL) {
        printf(" %d ", node->data);
        node = node->next;
    }
}

int main() {
    struct Node* head = NULL;
    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);
    push(&head, 8);
    push(&head, 9);
    push(&head, 10);
    push(&head, 11);
    push(&head, 12);
    push(&head, 13);

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    // Do stuff: deleteNode(&head, X);
    deleteNode(&head, 4);
    deleteNode(&head, 0);
    deleteNode(&head, 2);
    deleteNode(&head, 4);
    end = clock();

    cpu_time_used = ((double) (end - start)) * 1000 / CLOCKS_PER_SEC;

    puts("Created Linked List: ");
    printList(head);
    puts("\nLinked List after Deletion at position 4: ");
    printList(head);
    printf("\n\nTime taken by function: %f milliseconds\n", cpu_time_used);

    return 0;
}

