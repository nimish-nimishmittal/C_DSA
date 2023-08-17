#include <stdio.h>

struct Stack {
    int items[10];  // Assuming a maximum size of 10
    int top;
};

struct Stack stack; // Global stack variable

int isEmpty() {
    return stack.top == -1;
}

int isFull() {
    return stack.top == sizeof(stack.items) / sizeof(stack.items[0]) - 1;
}

void push(int item) {
    if (isFull()) {
        printf("Stack is full. Cannot push.\nIt is an Overflow condition.\n");
        return;
    }

    stack.top++;
    stack.items[stack.top] = item;
    printf("%d pushed onto the stack.\n", item);
}

int pop() {
    if (isEmpty()) {
        printf("Stack is empty. Cannot pop.\nIt is an Underflow condition.\n");
        return -1;
    }

    int poppedItem = stack.items[stack.top];
    stack.top--;
    return poppedItem;
}

void display() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack elements (LIFO order):\n");
    for (int i = stack.top; i >= 0; i--) {
        printf("%d\n", stack.items[i]);
    }
}

int main() {
    stack.top = -1; // Initialize the stack

    int choice, item;

    while (1) {
        printf("\nStack Operations Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item to push: ");
                scanf("%d", &item);
                push(item);
                break;
            case 2:
                item = pop();
                if (item != -1) {
                    printf("Popped: %d\n", item);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
