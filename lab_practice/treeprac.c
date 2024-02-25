#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct TreeNode{
    int data;
    struct TreeNode * left;
    struct TreeNode * right;
};

struct TreeNode * createNode(int data){
    struct TreeNode * treenode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    treenode->data = data;
    treenode->right = treenode->left = NULL;
    return treenode;
}

struct TreeNode * insertNode(struct TreeNode * root, int data){
    if(root->data = NULL){
        return createNode(data);
    }

    if(data < root->data){
        return insertNode(root->left, data);
    }
    else if(data > root->data){
        return insertNode(root->right, data);
    }

    return root;
}

void inOrderTraversal(struct TreeNode * root){
    if(root!=NULL){
        inOrderTraversal(root->left);
        printf(root->data);
        inOrderTraversal(root->right);
    }
}

void preOrderTraversal(struct TreeNode * root){
    if(root!=NULL){
        printf(root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void postOrderTraversal(struct TreeNode * root){
    if(root!=NULL){
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf(root->data);
    }
}

int main(){
    
    return 0;
}