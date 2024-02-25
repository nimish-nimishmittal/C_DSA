#include <stdio.h>
#include <stdlib.h>

// Node structure for threaded binary tree
struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
    int leftThread;  // 1 if left points to predecessor, 0 otherwise
    int rightThread; // 1 if right points to successor, 0 otherwise
};

// Function to create a new node
struct TreeNode *createNode(int data) {
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    newNode->leftThread = newNode->rightThread = 0; // Initially, no threads
    return newNode;
}

// Function to perform in-order traversal of threaded binary tree
void inOrderTraversal(struct TreeNode *root) {
    struct TreeNode *current = root;

    // Find the leftmost node
    while (current != NULL && current->leftThread == 0) {
        current = current->left;
    }

    // Traverse the tree using threads
    while (current != NULL) {
        printf("%d ", current->data);

        // If rightThread is 1, move to the inorder successor
        if (current->rightThread) {
            current = current->right;
        } else {
            // Otherwise, move to the leftmost node in the right subtree
            current = current->right;
            while (current != NULL && current->leftThread == 0) {
                current = current->left;
            }
        }
    }
}

// Function to perform pre-order traversal of threaded binary tree
void preOrderTraversal(struct TreeNode *root) {
    struct TreeNode *current = root;

    while (current != NULL) {
        printf("%d ", current->data);

        // If leftThread is 1, move to the inorder predecessor
        if (current->leftThread) {
            current = current->left;
        } else {
            // Otherwise, move to the left child
            current = current->left;

            // If rightThread is 1, move to the inorder successor
            if (current != NULL && current->rightThread) {
                current = current->right;
            }
        }
    }
}

// Function to perform post-order traversal of threaded binary tree
void postOrderTraversal(struct TreeNode *root) {
    if (root == NULL) {
        return;
    }

    struct TreeNode *current = root;
    struct TreeNode *prev = NULL;

    do {
        while (current != NULL) {
            if (current->rightThread == 0) {
                // If rightThread is not set, move to the right child
                current = current->right;
            } else {
                // If rightThread is set, process the node and move to the inorder successor
                printf("%d ", current->data);
                prev = current;
                current = current->right;
            }
        }

        // Move to the leftmost node in the right subtree if not backtracking
        current = prev->left;
        prev = NULL;
    } while (current != NULL);
}

// Function to insert a node into threaded binary tree
struct TreeNode *insertNode(struct TreeNode *root, int data) {
    struct TreeNode *newNode = createNode(data);
    struct TreeNode *current = root;
    struct TreeNode *parent = NULL;

    while (current != NULL) {
        parent = current;
        if (data < current->data) {
            if (current->leftThread == 0) {
                current = current->left;
            } else {
                break;
            }
        } else {
            if (current->rightThread == 0) {
                current = current->right;
            } else {
                break;
            }
        }
    }

    // Insert the new node
    if (parent == NULL) {
        // Tree is empty
        root = newNode;
    } else if (data < parent->data) {
        newNode->left = parent->left;
        newNode->right = parent;
        parent->left = newNode;
        parent->leftThread = 1;
    } else {
        newNode->right = parent->right;
        newNode->left = parent;
        parent->right = newNode;
        parent->rightThread = 1;
    }

    return root;
}

int main() {
    struct TreeNode *root = NULL;

    // Inserting nodes into threaded binary tree
    root = insertNode(root, 20);
    insertNode(root, 10);
    insertNode(root, 30);
    insertNode(root, 5);
    insertNode(root, 15);

    // Displaying the threaded binary tree using different traversal methods
    printf("In-Order Traversal: ");
    inOrderTraversal(root);
    printf("\n");

    printf("Pre-Order Traversal: ");
    preOrderTraversal(root);
    printf("\n");

    printf("Post-Order Traversal: ");
    postOrderTraversal(root);
    printf("\n");

    return 0;
}
