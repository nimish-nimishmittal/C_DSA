#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function to initialize the stack
void initialize(int stack[], int *top) {
    *top = -1;
}

// Function to check if the stack is empty
int isEmpty(int top) {
    return top == -1;
}

// Function to check if the stack is full
int isFull(int top) {
    return top == MAX_SIZE - 1;
}

// Function to push an element onto the stack
void push(int stack[], int *top, int value) {
    if (isFull(*top)) {
        printf("Stack Overflow: Cannot push element onto a full stack.\n");
    } else {
        stack[++(*top)] = value;
    }
}

// Function to pop an element from the stack
int pop(int stack[], int *top) {
    if (isEmpty(*top)) {
        printf("Stack Underflow: Cannot pop element from an empty stack.\n");
        return -1; // Return a sentinel value to indicate underflow
    } else {
        return stack[(*top)--];
    }
}

// Function to get the precedence of an operator
int getPrecedence(char operator) {
    switch (operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return -1; // Invalid operator
    }
}

// Function to convert infix expression to postfix
void infixToPostfix(char infix[], char postfix[]) {
    int stack[MAX_SIZE];
    int top = -1;

    int i = 0; // Index for infix expression
    int j = 0; // Index for postfix expression

    while (infix[i] != '\0') {
        if ((infix[i] >= '0' && infix[i] <= '9') || (infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z')) {
            postfix[j++] = infix[i++];
        } else if (infix[i] == '(') {
            push(stack, &top, infix[i++]);
        } else if (infix[i] == ')') {
            while (!isEmpty(top) && stack[top] != '(') {
                postfix[j++] = pop(stack, &top);
            }
            if (!isEmpty(top) && stack[top] == '(') {
                pop(stack, &top); // Discard the '(' from the stack
            }
            i++;
        } else {
            while (!isEmpty(top) && getPrecedence(infix[i]) <= getPrecedence(stack[top])) {
                postfix[j++] = pop(stack, &top);
            }
            push(stack, &top, infix[i++]);
        }
    }

    while (!isEmpty(top)) {
        postfix[j++] = pop(stack, &top);
    }

    postfix[j] = '\0'; // Null-terminate the postfix expression
}

// Function to evaluate postfix expression
int evaluatePostfix(char postfix[]) {
    int stack[MAX_SIZE];
    int top = -1;

    int i = 0;

    while (postfix[i] != '\0') {
        if (postfix[i] >= '0' && postfix[i] <= '9') {
            push(stack, &top, postfix[i] - '0');
        } else {
            int operand2 = pop(stack, &top);
            int operand1 = pop(stack, &top);

            switch (postfix[i]) {
                case '+':
                    push(stack, &top, operand1 + operand2);
                    break;
                case '-':
                    push(stack, &top, operand1 - operand2);
                    break;
                case '*':
                    push(stack, &top, operand1 * operand2);
                    break;
                case '/':
                    push(stack, &top, operand1 / operand2);
                    break;
                case '^':
                    push(stack, &top, operand1 ^ operand2);
                    break;
            }
        }
        i++;
    }

    return pop(stack, &top);
}

int main() {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("Result after evaluation: %d\n", result);

    return 0;
}
