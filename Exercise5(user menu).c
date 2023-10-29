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

// Function to search for a student by name and print the record
void searchStudentByName(struct Student* head, const char* targetName) {
    struct Student* current = head;
    int student_count = 1;
    int found = 0;

    while (current != NULL) {
        if (strcmp(current->name, targetName) == 0) {
            printf("%d-%s %d 20%d\n", current->number, current->name, current->age, student_count);
            found = 1;
        }
        current = current->next;
        student_count++;
    }

    if (!found) {
        printf("No student with the name '%s' found.\n", targetName);
    }
}

// Function to display the user menu
void displayMenu() {
    printf("\nUser Menu:\n");
    printf("1. Add Student\n");
    printf("2. Search Student by Name\n");
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
                searchStudentByName(student_list, searchName);
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
