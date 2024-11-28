#include <stdio.h>
#include <stdlib.h>

// Define the structure of a tree node
typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Function to find the maximum value in a subtree
TreeNode* findMax(TreeNode* node) {
    while (node && node->right) {
        node = node->right;
    }
    return node;
}

// Function to find the inorder predecessor of a given node in BST
TreeNode* findInorderPredecessor(TreeNode* root, TreeNode* target) {
    TreeNode* predecessor = NULL;

    while (root) {
        if (target->val > root->val) {
            // Go right, and update predecessor to the current node
            predecessor = root;
            root = root->right;
        } else if (target->val < root->val) {
            // Go left
            root = root->left;
        } else {
            // Node found
            if (target->left) {
                // If left subtree exists, find the maximum in the left subtree
                predecessor = findMax(target->left);
            }
            break;
        }
    }

    return predecessor;
}

// Helper function to create a new tree node
TreeNode* newNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Main function to test the code
int main() {
    // Create a sample BST
    TreeNode* root = newNode(20);
    root->left = newNode(10);
    root->right = newNode(30);
    root->left->left = newNode(5);
    root->left->right = newNode(15);
    root->right->left = newNode(25);
    root->right->right = newNode(35);

    TreeNode* target = root->left->right; // Node with value 15
    TreeNode* predecessor = findInorderPredecessor(root, target);

    if (predecessor) {
        printf("Inorder predecessor of %d is %d\n", target->val, predecessor->val);
    } else {
        printf("No inorder predecessor found for %d\n", target->val);
    }

    return 0;
}