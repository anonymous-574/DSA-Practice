#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
    Node(int x) {
      data = x;
      left = right = NULL;
    }
};

// Iterative method to find height of Binary Tree
void printLevelOrder(Node* root)
{
    if (root == NULL)
        return;

    // Create an empty queue for level order traversal
    queue <Node *> q;

    // Enqueue Root and initialize height
    q.push(root);

    while (q.empty() == false) {
        
        // Print front of queue and remove it from queue
        Node* node = q.front();
        cout << node->data << " ";
        q.pop();

        // Enqueue left child
        if (node->left != NULL)
            q.push(node->left);

        // Enqueue right child
        if (node->right != NULL)
            q.push(node->right);
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    printLevelOrder(root);
    return 0;
}