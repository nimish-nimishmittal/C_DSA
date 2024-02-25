#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char cityName[50];
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(char cityName[]) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->cityName, cityName);
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root, char cityName[]) {
    if (root == NULL) {
        return createNode(cityName);
    }

    if (strcmp(cityName, root->cityName) < 0) {
        root->left = insertNode(root->left, cityName);
    } else if (strcmp(cityName, root->cityName) > 0) {
        root->right = insertNode(root->right, cityName);
    }

    return root;
}

void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%s ", root->cityName);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%s ", root->cityName);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%s ", root->cityName);
    }
}

int main() {
    struct Node* root = NULL;
    root = insertNode(root, "Nimish Pur");
    root = insertNode(root, "Pune");
    root = insertNode(root, "Mumbai");
    root = insertNode(root, "Wadala");
    root = insertNode(root, "Thane");
    root = insertNode(root, "Chembur");

    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder Traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}
