#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack {
    char items[MAX_SIZE];
    int top;
};

void reverseString(char *input) {
    int length = strlen(input);

    for (int i = 0; i < length / 2; i++) {
        char temp = input[i];
        input[i] = input[length - 1 - i];
        input[length - 1 - i] = temp;
    }
}

int main() {
    char input[MAX_SIZE];

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove newline character

    reverseString(input);

    printf("Reversed string: %s\n", input);

    return 0;
}
