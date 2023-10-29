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

// Function to add all odd numbers to the beginning and even numbers to the end
void segregateOddsAndEvens(struct Node** head) {
    struct Node* odd_head = NULL;
    struct Node* even_head = NULL;
    struct Node* current = *head;

    while (current != NULL) {
        if (current->data == -1) {
            break; // Stop on -1
        }

        if (current->data % 2 == 0) {
            append(&even_head, current->data);
        } else {
            append(&odd_head, current->data);
        }

        current = current->next;
    }

    // Connect odd numbers list to even numbers list
    if (*head != NULL) {
        struct Node* last = odd_head;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = even_head;
    } else {
        *head = odd_head;
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
    int num;

    while (1) {
        printf("Enter a number (-1 to stop): ");
        scanf("%d", &num);

        if (num == -1) {
            break;
        }

        append(&head, num);
    }

    segregateOddsAndEvens(&head);
    printList(head);

    return 0;
}
