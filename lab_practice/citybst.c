#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for the binary search tree
struct TreeNode {
    char cityName[50];
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new node
struct TreeNode *createNode(const char *cityName) {
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    strcpy(newNode->cityName, cityName);
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the Binary Search Tree
struct TreeNode *insertNode(struct TreeNode *root, const char *cityName) {
    if (root == NULL) {
        return createNode(cityName);
    }

    int compareResult = strcmp(cityName, root->cityName);

    if (compareResult < 0) {
        root->left = insertNode(root->left, cityName);
    } else if (compareResult > 0) {
        root->right = insertNode(root->right, cityName);
    }

    return root;
}

// Function to perform Inorder traversal of the Binary Search Tree
void inOrderTraversal(struct TreeNode *root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%s\n", root->cityName);
        inOrderTraversal(root->right);
    }
}

// Function to perform Preorder traversal of the Binary Search Tree
void preOrderTraversal(struct TreeNode *root) {
    if (root != NULL) {
        printf("%s\n", root->cityName);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

// Function to perform Postorder traversal of the Binary Search Tree
void postOrderTraversal(struct TreeNode *root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%s\n", root->cityName);
    }
}

int main() {
    struct TreeNode *root = NULL;

    // Inserting nodes into the Binary Search Tree
    root = insertNode(root, "New York");
    insertNode(root, "Los Angeles");
    insertNode(root, "Chicago");
    insertNode(root, "Houston");
    insertNode(root, "Phoenix");
    insertNode(root, "Philadelphia");
    insertNode(root, "San Antonio");

    // Displaying the Binary Search Tree using different traversal methods
    printf("In-Order Traversal:\n");
    inOrderTraversal(root);
    printf("\n");

    printf("Pre-Order Traversal:\n");
    preOrderTraversal(root);
    printf("\n");

    printf("Post-Order Traversal:\n");
    postOrderTraversal(root);
    printf("\n");

    return 0;
}
