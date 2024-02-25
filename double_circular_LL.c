#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Employee {
    int empID;
    char name[50];
    struct Employee *prev;
    struct Employee *next;
};
struct Employee *createEmployee(int empID, const char *name) {
    struct Employee *newEmployee = (struct Employee *)malloc(sizeof(struct Employee));
    newEmployee->empID = empID;
    strcpy(newEmployee->name, name);
    newEmployee->prev = NULL;
    newEmployee->next = NULL;
    return newEmployee;
}
void insertEnd(struct Employee **head, struct Employee *newEmployee) {
    if (*head == NULL) {
        *head = newEmployee;
        (*head)->next = *head;
        (*head)->prev = *head;
    } else {
        struct Employee *last = (*head)->prev;
        last->next = newEmployee;
        newEmployee->prev = last;
        newEmployee->next = *head;
        (*head)->prev = newEmployee;
    }
}
void displayEmployees(struct Employee *head) {
    if (head == NULL) {
        printf("No employees to display.\n");
        return;
    }
    struct Employee *current = head;
    do {
        printf("Employee ID: %d, Name: %s\n", current->empID, current->name);
        current = current->next;
    } while (current != head);
}
void freeList(struct Employee *head) {
    if (head == NULL) {
        return;
    }
    struct Employee *current = head;
    struct Employee *temp;
    do {
        temp = current;
        current = current->next;
        free(temp);
    } while (current != head);
}
int main() {
    struct Employee *employeeList = NULL;
    insertEnd(&employeeList, createEmployee(1, "Nimish Mittal"));
    insertEnd(&employeeList, createEmployee(2, "Ramu Ranganathan"));
    insertEnd(&employeeList, createEmployee(3, "Shyam Shinde"));
    insertEnd(&employeeList, createEmployee(4, "Aradhana Mittal"));
    insertEnd(&employeeList, createEmployee(5, "Vasant Gawde"));
    displayEmployees(employeeList);
    freeList(employeeList);
    return 0;
}
