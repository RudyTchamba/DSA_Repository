#include <stdio.h>
#include <stdlib.h>

typedef enum{
    false,
    true
}Bool;

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;

// Function to create a new node
Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to get the height of a node
int getHeight(Node* node) {
    if (node == NULL) {
        return 0;
    }
    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);
    if (leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1) {
        return -1;
    }
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

// Function to check if a tree is balanced
Bool isBalanced(Node* root){
    return getHeight(root) != -1;
}

int main(){
    // Create a balanced binary tree
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    if (isBalanced(root)) {
        printf("The tree is balanced.\n");
    } else {
        printf("The tree is not balanced.\n");
    }

    // Create an unbalanced binary tree
    Node* unbalancedRoot = newNode(1);
    unbalancedRoot->left = newNode(2);
    unbalancedRoot->right = newNode(3);
    unbalancedRoot->left->left = newNode(4);
    unbalancedRoot->left->left->left = newNode(5);

    if (isBalanced(unbalancedRoot)) {
        printf("The tree is balanced.\n");
    } else {
        printf("The tree is not balanced.\n");
    }

    return 0;
}