#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *deleteStart(struct Node *head) {
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct Node *deleteBetween(struct Node *head, int index) {
    struct Node *ptr = head;
    int i = 0;
    while (i != index - 1) {
        ptr = ptr->next;
        i++;
    }
    struct Node *p = ptr->next;
    ptr->next = p->next;
    free(p);
    return head;
}

struct Node *deleteLast(struct Node *head) {
    struct Node *ptr = head;
    while (ptr->next->next != NULL) {
        ptr = ptr->next;
    }
    struct Node *p = ptr->next;
    ptr->next = NULL;
    free(p);
    return head;
}

struct Node *insertAtFirst(struct Node *head, int data) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

struct Node *insertInBetween(struct Node *head, int data, int index) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;

    while (i != index - 1) {
        p = p->next;
        i++;
    }

    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;

    return head;
}

struct Node *insertAtEnd(struct Node *head, int data) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;

    while (p->next != NULL) {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

void LLTraversal(struct Node *ptr) {
    while (ptr != NULL) {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main() {
    struct Node *head = NULL;
    int choice, data, index;

    do {
        printf("\n1. Insert at First\n");
        printf("2. Insert in Between\n");
        printf("3. Insert at End\n");
        printf("4. Delete from Start\n");
        printf("5. Delete in Between\n");
        printf("6. Delete from End\n");
        printf("7. Display List\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at first: ");
                scanf("%d", &data);
                head = insertAtFirst(head, data);
                break;

            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter index to insert at: ");
                scanf("%d", &index);
                head = insertInBetween(head, data, index);
                break;

            case 3:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;

            case 4:
                head = deleteStart(head);
                break;

            case 5:
                printf("Enter index to delete: ");
                scanf("%d", &index);
                head = deleteBetween(head, index);
                break;

            case 6:
                head = deleteLast(head);
                break;

            case 7:
                printf("Linked List:\n");
                LLTraversal(head);
                break;

            case 0:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 0);

    return 0;
}
