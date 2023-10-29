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

int main() {
    struct Student* student_list = NULL;

    // Add student information
    addStudent(&student_list, 1, "Saliha", 27);
    addStudent(&student_list, 2, "Ece", 19);

    // Print student information and count
    printStudents(student_list);

    return 0;
}
