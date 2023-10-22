#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the threaded binary tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int isThreaded;  // Flag to indicate whether right pointer is a thread
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    newNode->isThreaded = 0; // Initially, the right pointer is not a thread
    return newNode;
}

// Function to perform Inorder traversal of threaded binary tree
void inorderTraversal(struct Node* root) {
    struct Node* current = leftmost(root);

    while (current != NULL) {
        printf("%d ", current->data);

        // If the right pointer is a thread, move to the inorder successor
        if (current->isThreaded) {
            current = current->right;
        } else {
            // Otherwise, move to the leftmost node in the right subtree
            current = leftmost(current->right);
        }
    }
}

// Function to find the leftmost node in a subtree
struct Node* leftmost(struct Node* node) {
    if (node == NULL)
        return NULL;

    while (node->left != NULL)
        node = node->left;

    return node;
}

// Function to insert a new node into the threaded binary tree
struct Node* insertNode(struct Node* root, int data) {
    // If the tree is empty, create a new node
    if (root == NULL)
        return createNode(data);

    // Find the position to insert the new node
    if (data < root->data) {
        // Insert into the left subtree
        root->left = insertNode(root->left, data);

        // If the left subtree is threaded, update the thread
        if (root->left->right == NULL) {
            root->left->right = root;
            root->left->isThreaded = 1;
        }
    } else if (data > root->data) {
        // Insert into the right subtree
        root->right = insertNode(root->right, data);

        // If the right subtree is threaded, update the thread
        if (root->right->left == NULL) {
            root->right->left = root;
            root->right->isThreaded = 1;
        }
    }

    return root;
}

// Main function
int main() {
    struct Node* root = NULL;

    // Inserting nodes into the threaded binary tree
    root = insertNode(root, 20);
    root = insertNode(root, 10);
    root = insertNode(root, 30);
    root = insertNode(root, 5);
    root = insertNode(root, 15);

    // Traversing and printing the threaded binary tree
    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
