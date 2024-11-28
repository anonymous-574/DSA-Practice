#include <stdio.h>
#include <stdlib.h>

typedef struct Tree {
    int data;
    int bf;
    struct Tree* left;
    struct Tree* right;
} Tree;

void LVR(Tree* root) {
    if (root == NULL) return;
    LVR(root->left);
    printf("%d(%d)->", root->data, root->bf);
    LVR(root->right);
}

Tree * find5=NULL;
void find1(Tree* root , int val) {
    if (root == NULL) return;
    find1(root->left,val);
    if (root->data==val)
    {
        find5=root;
    }
    
    find1(root->right,val);
}


Tree* addNode(int data) {
    Tree* p = malloc(sizeof(Tree));
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    p->bf = 0;
    return p;
}

int height(Tree* root) {
    if (root == NULL) return -1;
    int lh = height(root->left);
    int rh = height(root->right);
    return (lh > rh ? lh : rh) + 1;
}

Tree* updatebf(Tree* root) {
    if (root == NULL) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    root->bf = lh - rh;
    return root;
}

Tree* createTree(Tree* root, int data) {
    if (root == NULL) {
        return addNode(data);
    }
    if (data < root->data) {
        root->left = createTree(root->left, data);
        updatebf(root);
    } else {
        root->right = createTree(root->right, data);
        updatebf(root);
    }
    return root;
}

int leaves(Tree* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    return leaves(root->left) + leaves(root->right);
}

void minmaxkey(Tree* root) {
    Tree* min = root->left;
    Tree* max = root->right;
    Tree* min1 = min;
    Tree* max1 = max;
    while (min != NULL) {
        min1 = min;
        min = min->left;
    }
    if (root->left != NULL) printf("Minimum key of %d: %d", root->data, min1->data);
    else printf("Minimum doesn't exist...");
    while (max != NULL) {
        max1 = max;
        max = max->right;
    }
    if (root->right != NULL) printf("\nMaximum key of %d: %d", root->data, max1->data);
    else printf("\nMaximum doesn't exist...");
}

Tree* find(Tree* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) return find(root->left, data);
    else return find(root->right, data);
}

void predecessor(Tree* root, int key) {
    Tree* pred = NULL;
    while (root != NULL) {
        if (key < root->data) {
            root = root->left;
        }
        else if (key > root->data) {
            pred = root;
            root = root->right;
        }
        else {
            if (root->left != NULL) {
                root = root->left;
                while (root->right != NULL) {
                    root = root->right;
                }
                pred = root;
            }
            break;
        }
    }
    if (pred != NULL) printf("Predecessor: %d\n", pred->data);
    else printf("No predecessor found\n");
}

void successor(Tree* root, int key) {
    Tree* succ = NULL;
    while (root != NULL) {
        if (key < root->data) {
            succ = root;
            root = root->left;
        }
        else if (key > root->data) {
            root = root->right;
        }
        else {
            if (root->right != NULL) {
                root = root->right;
                while (root->left != NULL) {
                    root = root->left;
                }
                succ = root;
            }
            break;
        }
    }
    if (succ != NULL) printf("Successor: %d\n", succ->data);
    else printf("No successor found\n");
}

int main() {
    int n;
    printf("Enter no. of elements: ");
    scanf("%d", &n);
    int arr[n];
    Tree* root = NULL;
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        root = createTree(root, arr[i]);
    }
    printf("LVR: ");
    LVR(root);
    
    int k;
    printf("\nTo find min max key: ");
    scanf("%d", &k);
    minmaxkey(find(root, k));

    printf("\nLeaves: %d", leaves(root));
    
    int h;
    printf("\nTo find height: ");
    scanf("%d", &h);
    printf("Height = %d\n", height(find(root, h)));
    
    int key;
    printf("\nEnter key to find predecessor and successor: ");
    scanf("%d", &key);
    predecessor(root, key);
    successor(root, key);

    return 0;
}