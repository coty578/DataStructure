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

// Function to delete the next node after the student with a given name
void deleteNextNode(struct Student** head, const char* targetName) {
    struct Student* current = *head;

    while (current != NULL) {
        if (strcmp(current->name, targetName) == 0 && current->next != NULL) {
            struct Student* temp = current->next;
            current->next = temp->next;
            free(temp); // Delete the next node
            return;
        }
        current = current->next;
    }
}

// Function to print the linked list
void printStudents(struct Student* head) {
    struct Student* current = head;
    while (current != NULL) {
        printf("%d-%s %d 20%d\n", current->number, current->name, current->age, current->number);
        current = current->next;
    }
}

int main() {
    struct Student* student_list = NULL;

    // Add student information
    addStudent(&student_list, 1, "Saliha", 27);
    addStudent(&student_list, 2, "Ece", 19);
    addStudent(&student_list, 3, "John", 21);

    // Print the original list
    printf("Original List:\n");
    printStudents(student_list);

    // Search for a student by name and delete the next node
    const char* searchName = "Saliha";
    deleteNextNode(&student_list, searchName);

    // Print the modified list
    printf("Modified List:\n");
    printStudents(student_list);

    return 0;
}
