#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void deleteNode(struct Node** head_ref, struct Node* del) {
    if (*head_ref == NULL || del == NULL)
        return;

    if (*head_ref == del)
        *head_ref = del->next;

    if (del->next != NULL)
        del->next->prev = del->prev;

    if (del->prev != NULL)
        del->prev->next = del->next;

    free(del);
}

void insertAfter(struct Node* prev_node, int new_data) {
    if (prev_node == NULL)
        return;

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    new_node->prev = prev_node;

    if (prev_node->next != NULL)
        prev_node->next->prev = new_node;

    prev_node->next = new_node;
}

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->prev = NULL;
    new_node->next = (*head_ref);
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;

    (*head_ref) = new_node;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    struct Node* head = NULL;
    srand(time(NULL));

    push(&head, 2);
    push(&head, 4);
    push(&head, 8);
    push(&head, 10);

    for (int i = 0; i < 10; i++) {
        int new_data = rand() % 100;
        struct Node* current = head;
        int n = rand() % (i + 5); // Posisi acak, asumsi list sudah memiliki 4 node
        for (int j = 0; j < n && current->next != NULL; j++)
            current = current->next;
        insertAfter(current, new_data);
    }

    for (int i = 0; i < 3; i++) {
        struct Node* current = head;
        int n = rand() % (14 - i); // Posisi acak, list sekarang memiliki 14 node
        for (int j = 0; j < n; j++)
            current = current->next;
        deleteNode(&head, current);
    }

    printf("\nLinked list setelah penambahan dan penghapusan: ");
    printList(head);

    getchar();
    return 0;
}

