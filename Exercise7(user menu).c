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

// Function to find and print the record with the longest name
void printLongestNameRecord(struct Student* head) {
    struct Student* current = head;
    char longestName[50] = "";
    int maxLength = 0;

    while (current != NULL) {
        int currentLength = strlen(current->name);
        if (currentLength > maxLength) {
            maxLength = currentLength;
            strcpy(longestName, current->name);
        }
        current = current->next;
    }

    if (maxLength > 0) {
        printf("The longest name in the list: %s Length: %d\n", longestName, maxLength);
    } else {
        printf("No student records in the list.\n");
    }
}

// Function to display the user menu
void displayMenu() {
    printf("\nUser Menu:\n");
    printf("1. Add Student\n");
    printf("2. Print Longest Name Record\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    struct Student* student_list = NULL;
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Call your function to add a student
                break;
            case 2:
                printLongestNameRecord(student_list);
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
