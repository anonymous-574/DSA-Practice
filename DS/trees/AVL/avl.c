#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node * left;
    struct node * right;
    int height;
};

int max(int a, int b)
{
    return a>b?a:b;
}

void preorder(struct node * root)
{
    if (root!=NULL)
    {
        printf("%d \n",root->data);
        preorder(root->left); 
        preorder(root->right);
    }
}

void postorder(struct node * root)
{
    if (root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d \n",root->data);
    }
}

void inorder(struct node * root)
{
    if (root!=NULL)
    {
        inorder(root->left);
        printf("%d \n",root->data);
        inorder(root->right);
    }
}

int get_height(struct node * n)
{
    if (n==NULL)
    {
        return 0;
    }
    return n->height;
}

int get_bal_f(struct node * n)
{
    if (n==NULL)
    {
        return 0;
    }
    return get_height(n->left) - get_height(n->right);
}

struct node * create_node(int d)
{
    struct node * ptr = (struct node * ) malloc(sizeof(struct node));
    ptr->left=NULL;
    ptr->right=NULL;
    ptr->data=d;
    return ptr;
}

struct node * right_rotate(struct node * y)
{
    struct node * x = y->left;
    struct node * T2= x->right;

    x->right=y;
    y->left=T2;
    
    x->height= max(get_height(x->left) , get_height(x->right)) +1;
    y->height= max(get_height(y->left) , get_height(y->right)) +1;

    return x;
}

struct node * left_rotate(struct node * x)
{
    struct node * y = x->right;
    struct node * T2= y->left;

    y->left=x;
    x->right=T2;
    
    x->height= max(get_height(x->left) , get_height(x->right)) +1;
    y->height= max(get_height(y->left) , get_height(y->right)) +1;

    return y;
}

struct node * insert(struct node * root , int data)
{
    if (root==NULL)
        return create_node(data);
    
    if (data <root->data)
        root->left=insert(root->left,data);
    else if (data>root->data)
        root->right=insert(root->right,data);
        return root;
    
    
    //we are using recursion
    //dont worry the height will be updated from leaf node onwards (on the path we are on)
    root->height= 1+ max( get_height(root->left), get_height(root->right));
    int bf = get_bal_f(root);


    //recursion always the lowest unbalanced node

    //LL
    if (bf>1 && root->left!=NULL && data < root->left->data)
    {
        return right_rotate(root);
    }
    
    //RR
    if (bf<-1 && root->right!=NULL && data > root->right->data )
    {
        return left_rotate(root);
    }

    //LR
    if (bf>1 && root->left!=NULL && data > root->left->data)
    {
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }

    //RL
    if (bf<-1 && root->right!=NULL && data < root->right->data)
    {
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }

    return root;
}

struct Node *minValueNode(struct Node *node){
   struct node *current = node;
   while (current->left != NULL)
      current = current->left;
   return current;
}
struct Node *deleteNode(struct node *root, int data)
{
   if (root == NULL)
      return root;
   if (data < root->data)
      root->left = deleteNode(root->left, data);
   else if (data > root->data)
      root->right = deleteNode(root->right, data);
   else {
      if ((root->left == NULL) || (root->right == NULL)) {
         struct node *temp = root->left ? root->left : root->right;
         if (temp == NULL) {
            temp = root;
            root = NULL;
         } else
            *root = *temp;
         free(temp);
      } else {
         struct node *temp = minValueNode(root->right);
         root->data = temp->data;
         root->right = deleteNode(root->right, temp->data);
      }
   }
   if (root == NULL)
      return root;
   root->height = 1 + max(get_height(root->left),
                     get_height(root->right));
   int balance = get_bal_f(root);
   if (balance > 1 && get_bal_f(root->left) >= 0)
      return rightRotate(root);
   if (balance > 1 && get_bal_f(root->left) < 0) {
      root->left = left_rotate(root->left);
      return right_rotate(root);
   }
   if (balance < -1 && get_bal_f(root->right) <= 0)
      return leftRotate(root);
   if (balance < -1 && get_bal_f(root->right) > 0) {
      root->right = right_rotate(root->right);
      return left_rotate(root);
   }
   return root;
}


struct node * search(struct node * root, int key)
{
    if (root==NULL)
    {
        return NULL;
    }
    if (root->data=key)
    {
        return root;
    }
    else if (root->data>key)
    {
        search(root->left,key);
    }
    else
    {
        search(root->right,key);
    }
} 

void free_tree (struct node * root)
{
    if (root==NULL)
    {
        return;
    }
    
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

int main(int argc, char const *argv[])
{
    struct node * root =NULL;
    
    root= insert(root,16);
    root=insert(root,14);
    root=insert(root,3);
    root=insert(root,2);
    root=insert(root,11);
    root=insert(root,12);
    preorder(root);
    printf("\n\n\n");
    printf("HI");
    root = deletenode(root,2);
    preorder(root);
    printf("\n\n\n");
    //printf("\n\n\n");
    //postorder(root);
    //printf("\n\n\n");
    //inorder(root);
    
    

    free_tree(root);
    return 0;
}
