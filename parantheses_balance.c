#include <stdio.h>

struct Stack {
    char data[100];
    int top;
};

void push(struct Stack* stack, char item) {
    if (stack->top == sizeof(stack->data) / sizeof(stack->data[0]) - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack->top++;
    stack->data[stack->top] = item;
}

char pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack underflow\n");
        return '\0';
    }
    char item = stack->data[stack->top];
    stack->top--;
    return item;
}

int areParenthesesBalanced(const char* expression) {
    struct Stack stack;
    stack.top = -1; 

    for (int i = 0; expression[i] != '\0'; i++) {
        if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[') {
            push(&stack, expression[i]);
        } else if (expression[i] == ')' || expression[i] == '}' || expression[i] == ']') {
            if (stack.top == -1) {
                return 0; 
            }
            char popped = pop(&stack);
            if ((expression[i] == ')' && popped != '(') ||
                (expression[i] == '}' && popped != '{') ||
                (expression[i] == ']' && popped != '[')) {
                return 0; 
            }
        }
    }

    return (stack.top == -1); 
}

int main() {
    char expression[100];
    printf("Enter an expression: ");
    scanf("%s", expression);

    if (areParenthesesBalanced(expression)) {
        printf("The parentheses are balanced.\n");
    } else {
        printf("The parentheses are not balanced.\n");
    }

    return 0;
}
