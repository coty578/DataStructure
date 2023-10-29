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

// Function to search for a student by name
struct Student* searchStudentByName(struct Student* head, const char* targetName) {
    struct Student* current = head;

    while (current != NULL) {
        if (strcmp(current->name, targetName) == 0) {
            return current; // Student found
        }
        current = current->next;
    }

    return NULL; // Student not found
}

int main() {
    struct Student* student_list = NULL;

    // Add student information
    addStudent(&student_list, 1, "Saliha", 27);
    addStudent(&student_list, 2, "Ece", 19);

    // Search for a student by name
    const char* searchName = "Ece";
    struct Student* foundStudent = searchStudentByName(student_list, searchName);

    if (foundStudent != NULL) {
        printf("Student found: %d-%s %d 20%d\n", foundStudent->number, foundStudent->name, foundStudent->age, foundStudent->number);
    } else {
        printf("Student not found.\n");
    }

    return 0;
}
