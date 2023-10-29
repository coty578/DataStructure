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

// Function to add a student to the linked list
void addStudent(struct Student** head, int number, const char* name, int age) {
    struct Student* new_student = (struct Student*)malloc(sizeof(struct Student));
    new_student->number = number;
    strcpy(new_student->name, name);
    new_student->age = age;
    new_student->next = NULL;

    if (*head == NULL) {
        *head = new_student;
    } else {
        struct Student* last = *head;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = new_student;
    }
}

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

int main() {
    struct Student* student_list = NULL;

    // Add student information
    addStudent(&student_list, 1, "Abdurrahmangazi", 25);
    addStudent(&student_list, 2, "Ece", 19);
    addStudent(&student_list, 3, "JohnSmithJohnson", 21);

    // Print the record with the longest name
    printLongestNameRecord(student_list);

    return 0;
}
