#include <stdio.h>
#include <string.h>

struct Stack {
    char items[100];
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

int isPalindrome(char *input) {
    int length = strlen(input);

    for (int i = 0; i < length / 2; i++) {
        if (input[i] != input[length - 1 - i]) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char input[100];

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    reverseString(input);

    printf("Reversed string: %s\n", input);

    if (isPalindrome(input)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}
