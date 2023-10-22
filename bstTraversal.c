#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a node in the BST
struct Node {
    char cityName[50];
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(char cityName[]) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->cityName, cityName);
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the BST
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

// Function for Inorder traversal
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%s ", root->cityName);
        inorderTraversal(root->right);
    }
}

// Function for Preorder traversal
void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%s ", root->cityName);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Function for Postorder traversal
void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%s ", root->cityName);
    }
}

// Main function
int main() {
    struct Node* root = NULL;

    // Inserting cities into the BST
    root = insertNode(root, "New York");
    root = insertNode(root, "Los Angeles");
    root = insertNode(root, "Chicago");
    root = insertNode(root, "Houston");
    root = insertNode(root, "Phoenix");

    // Traversing and printing the BST
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
