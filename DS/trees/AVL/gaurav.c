#include <stdio.h>
#include <stdlib.h>
#include <sys/param.h>
 
typedef struct Node {
    int val;
    struct Node *left;
    struct Node *right;
} Node;
 
int max (int a , int b){return a>b?a:b;}

int height(Node *root) {
    if (root == NULL) return -1;
    return 1 + max(height(root->left), height(root->right));
}
 
Node *insert(Node *root, int val) {
    if (!root) {
        Node *t = calloc(1, sizeof(Node));
        t->val = val;
        return t;
    }
 
    if (root->val > val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
 
    int bf = height(root->left) - height(root->right);
 
    if (bf < -1) {
        Node *temp = root->right->left;
        Node *temp2 = root->right;
        root->right->left = root;
        root->right = temp;
        return temp2;
    }
    return root;
}
 
void inorder(Node *root) {
    if (root) {
        inorder(root->left);
        printf("%d, ", root->val);
        inorder(root->right);
    }
}
void preorder(Node *root) {
    if (root) {
        printf("%d, ", root->val);
        preorder(root->left);
        preorder(root->right);
    }
}
 
int main() {
    Node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    /*root = insert(root, 5);*/
    /*root = insert(root, 7);*/
    /*root = insert(root, 17);*/
 
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
}