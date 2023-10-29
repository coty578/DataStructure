#include <stdio.h>
#include <stdlib.h>

// Define the structure for a student
struct Student {
    int number;
    char name[50];
    int age;
    struct Student* next;
};

// Function to add a student to the linked list (You can create your own function for this)

// Function to traverse and print student information
void printStudents(struct Student* head) {
    struct Student* current = head;
    int student_count = 1;

    while (current != NULL) {
        printf("%d-%s %d 20%d\n", current->number, current->name, current->age, student_count);
        current = current->next;
        student_count++;
    }
}

// Function to count the number of students
int countStudents(struct Student* head) {
    int count = 0;
    struct Student* current = head;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

// Function to display the user menu
void displayMenu() {
    printf("\nUser Menu:\n");
    printf("1. Add Student\n");
    printf("2. Print Student Information\n");
    printf("3. Count Students\n");
    printf("4. Exit\n");
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
                // Call your function to print student information
                break;
            case 3:
                // Call your function to count students
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    } while (choice != 4);

    // Cleanup or free memory for your data structure

    return 0;
}
