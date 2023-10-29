#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list (You can create your own data structure here)

// Function to add odd and even numbers to the list (You can use your own function for this)

// Function to display the user menu
void displayMenu() {
    printf("\nUser Menu:\n");
    printf("1. Add Odd and Even Numbers to the List\n");
    printf("2. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    // Initialize your linked list or data structure here

    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Call your function to add odd and even numbers
                break;
            case 2:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    } while (choice != 2);

    // Cleanup or free memory for your data structure

    return 0;
}
