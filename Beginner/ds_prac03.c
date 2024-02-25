#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure to store student information
struct Student {
    int prn;
    char name[50];
    float marks;
    struct Student *next;
};

// Function to insert a new student at the beginning of the linked list
struct Student* insertStudent(struct Student *head, int prn, const char *name, float marks) {
    struct Student *newStudent = (struct Student*)malloc(sizeof(struct Student));
    newStudent->prn = prn;
    strcpy(newStudent->name, name);
    newStudent->marks = marks;
    newStudent->next = head;
    return newStudent;
}

// Function to display data of the top rank student
void displayTopRank(struct Student *head) {
    if (head == NULL) {
        printf("No students in the list.\n");
        return;
    }

    struct Student *topStudent = head;
    struct Student *current = head->next;

    while (current != NULL) {
        if (current->marks > topStudent->marks) {
            topStudent = current;
        }
        current = current->next;
    }

    printf("Top Rank Student:\n");
    printf("PRN: %d\n", topStudent->prn);
    printf("Name: %s\n", topStudent->name);
    printf("Marks: %.2f\n", topStudent->marks);
}

// Function to count the number of students securing first class and above
int countFirstClassAndAbove(struct Student *head) {
    if (head == NULL) {
        return 0;
    }

    int count = 0;
    struct Student *current = head;

    while (current != NULL) {
        if (current->marks >= 60.0) {
            count++;
        }
        current = current->next;
    }

    return count;
}

// Function to display all students in the list
void displayAllStudents(struct Student *head) {
    if (head == NULL) {
        printf("No students in the list.\n");
        return;
    }

    printf("Student Information:\n");
    struct Student *current = head;
    while (current != NULL) {
        printf("PRN: %d, Name: %s, Marks: %.2f\n", current->prn, current->name, current->marks);
        current = current->next;
    }
}

int main() {
    struct Student *head = NULL;

    // Inserting sample student data
    head = insertStudent(head, 123, "John Doe", 85.5);
    head = insertStudent(head, 124, "Jane Smith", 70.2);
    head = insertStudent(head, 125, "Bob Johnson", 92.0);

    // Displaying all students
    displayAllStudents(head);

    // Displaying data of the top rank student
    displayTopRank(head);

    // Counting students securing first class and above
    int firstClassCount = countFirstClassAndAbove(head);
    printf("Number of students securing first class and above: %d\n", firstClassCount);

    return 0;
}
