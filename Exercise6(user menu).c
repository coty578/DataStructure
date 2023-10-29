#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a student
struct Student {
    int number;
    char name[50];
    int age;
    struct Student* next;
};

// Function to add a student to the linked list (You can create your own function for this)

// Function to delete the next node from the node with the searched student name
void deleteNextNodeByName(struct Student* head, const char* targetName) {
    struct Student* current = head;
    struct Student* previous = NULL;
    int found = 0;

    while (current != NULL) {
        if (strcmp(current->name, targetName) == 0) {
            if (current->next != NULL) {
                struct Student* nextNode = current->next;
                current->next = nextNode->next;
                free(nextNode);
                found = 1;
                printf("Deleted the next node after '%s'.\n", targetName);
            } else {
                printf("No next node to delete after '%s'.\n", targetName);
            }
        }
        previous = current;
        current = current->next;
    }

    if (!found) {
        printf("No student with the name '%s' found.\n", targetName);
    }
}

// Function to display the user menu
void displayMenu() {
    printf("\nUser Menu:\n");
    printf("1. Add Student\n");
    printf("2. Delete Next Node by Student Name\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    struct Student* student_list = NULL;
    int choice;
    char searchName[50];

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Call your function to add a student
                break;
            case 2:

                printf("Enter the name to search for: ");
                scanf("%s", searchName);
                deleteNextNodeByName(student_list, searchName);
                break;
            case 3:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    } while (choice != 3);

    // Cleanup or free memory for your data structure

    return 0;
}
