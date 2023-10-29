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

// Function to sort the linked list in descending order
void sortDescending(struct Node** head) {
    struct Node* current = *head;
    struct Node* next_node;
    int temp;

    while (current != NULL) {
        next_node = current->next;

        while (next_node != NULL) {
            if (current->data < next_node->data) {
                temp = current->data;
                current->data = next_node->data;
                next_node->data = temp;
            }
            next_node = next_node->next;
        }
        current = current->next;
    }
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf("->");
        }
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Add 100 randomly generated numbers to the list
    for (int i = 0; i < 100; i++) {
        int random_num = rand() % 100; // Modify the range as needed
        append(&head, random_num);
    }

    sortDescending(&head); // Sort the list in descending order
    printList(head); // Print the sorted list

    return 0;
}
