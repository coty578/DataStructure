#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to add a node at the end of the linked list
void append(struct Node** head, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    struct Node* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

// Function to print the linked list with the specified structure
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            if (current->data % 2 == 0 && current->next->data % 2 == 0) {
                printf("-");
            } else {
                printf("->");
            }
        }
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Add the specified numbers to the list
    int numbers[] = {54, 58, 62, 65, 71, 73, 102};
    for (int i = 0; i < 7; i++) {
        append(&head, numbers[i]);
    }

    printList(head); // Print the list with the specified structure

    return 0;
}

