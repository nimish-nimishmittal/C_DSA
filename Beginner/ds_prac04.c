#include <stdio.h>
#include <stdlib.h>

// Node structure to store employee information
struct Employee {
    char name[50];
    float salary;
    int age;
    struct Employee *prev;
    struct Employee *next;
};

// Function to insert a new employee at the end of the doubly linked list
struct Employee* insertEmployee(struct Employee *head, const char *name, float salary, int age) {
    struct Employee *newEmployee = (struct Employee*)malloc(sizeof(struct Employee));
    strcpy(newEmployee->name, name);
    newEmployee->salary = salary;
    newEmployee->age = age;
    newEmployee->prev = NULL;
    newEmployee->next = NULL;

    if (head == NULL) {
        return newEmployee;
    }

    struct Employee *current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newEmployee;
    newEmployee->prev = current;

    return head;
}

// Function to display data of employees with salary more than 50,000
void displayHighSalaryEmployees(struct Employee *head) {
    if (head == NULL) {
        printf("No employees in the list.\n");
        return;
    }

    printf("Employees with Salary > 50,000:\n");
    struct Employee *current = head;
    while (current != NULL) {
        if (current->salary > 50000) {
            printf("Name: %s, Salary: %.2f, Age: %d\n", current->name, current->salary, current->age);
        }
        current = current->next;
    }
}

// Function to display a list of employees with age less than 30 and salary greater than 30,000
void displayYoungHighSalaryEmployees(struct Employee *head) {
    if (head == NULL) {
        printf("No employees in the list.\n");
        return;
    }

    printf("Employees with Age < 30 and Salary > 30,000:\n");
    struct Employee *current = head;
    while (current != NULL) {
        if (current->age < 30 && current->salary > 30000) {
            printf("Name: %s, Salary: %.2f, Age: %d\n", current->name, current->salary, current->age);
        }
        current = current->next;
    }
}

// Function to display all employees in the list
void displayAllEmployees(struct Employee *head) {
    if (head == NULL) {
        printf("No employees in the list.\n");
        return;
    }

    printf("Employee Information:\n");
    struct Employee *current = head;
    while (current != NULL) {
        printf("Name: %s, Salary: %.2f, Age: %d\n", current->name, current->salary, current->age);
        current = current->next;
    }
}

int main() {
    struct Employee *head = NULL;

    // Inserting sample employee data
    head = insertEmployee(head, "John Doe", 60000.0, 25);
    head = insertEmployee(head, "Jane Smith", 55000.0, 28);
    head = insertEmployee(head, "Bob Johnson", 70000.0, 32);

    // Displaying all employees
    displayAllEmployees(head);

    // Displaying employees with salary more than 50,000
    displayHighSalaryEmployees(head);

    // Displaying employees with age less than 30 and salary greater than 30,000
    displayYoungHighSalaryEmployees(head);

    return 0;
}