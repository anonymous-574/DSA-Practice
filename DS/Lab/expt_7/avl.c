#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node * left;
    struct node * right;
    int height;
}node;

int max(int a, int b)
{
    return a>b?a:b;
}

void preorder(node * root)
{
    if (root!=NULL)
    {
        printf("%d \n",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node * root)
{
    if (root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d \n",root->data);
    }
}

void inorder(node * root)
{
    if (root!=NULL)
    {
        inorder(root->left);
        printf("%d \n",root->data);
        inorder(root->right);
    }
}


int get_height(node * n)
{
    return n?n->height:0;
}

int get_bal_f(node * n)
{
    return n?get_height(n->left) - get_height(n->right):0;
}

node * create_node(int d)
{
    node * ptr = (node * ) malloc(sizeof(node));
    ptr->left=NULL;
    ptr->right=NULL;
    ptr->data=d;
    ptr->height=1;
    return ptr;
}

void preorder_with_bal(node * root)
{
    if (root!=NULL)
    {
        printf("%d (%d) ,", root->data, get_bal_f(root));
        preorder_with_bal(root->left);
        preorder_with_bal(root->right);
    }
}

node * right_rotate(node * root)
{
   struct node *rightPtr=root->right;
   struct node *temp=rightPtr->left;
   rightPtr->left=root;
   root->right=temp;

    root->height = max(get_height(root->left),get_height(root->right)) + 1;
    rightPtr->height = max(get_height(rightPtr->left),get_height(rightPtr->right)) + 1;

    return rightPtr;
}

node * left_rotate(node * root)
{
    struct node *leftPtr=root->left;
   struct node *temp=leftPtr->right;
   leftPtr->right=root;
   root->left=temp;

    root->height = max(get_height(root->left),get_height(root->right)) + 1;
    leftPtr->height = max(get_height(leftPtr->left),get_height(leftPtr->right)) + 1;

    return leftPtr;
}


node * insert(node * root , int data)
{
    if (root==NULL)
        return create_node(data);
    if (data <root->data)
        root->left=insert(root->left,data);
    else if (data>root->data)
        root->right=insert(root->right,data);


    //we are using recursion
    //dont worry the height will be updated from leaf node onwards (on the path we are on)
    root->height= 1+ max( get_height(root->left), get_height(root->right));
    int bf = get_bal_f(root);

    printf("Before Impending Rotation After Insertion: \n");
    preorder(root);
    printf("\n");


    
    //recursion always gives the lowest unbalanced node

    //LL
    if (bf>1 && root->left!=NULL && data < root->left->data)
    {
        printf("Appying LL Rotation \n");
        return left_rotate(root);
    }
    
    //RR
    if (bf<-1 && root->right!=NULL && data > root->right->data )
    {
        printf("Appying RR Rotation \n");
        return right_rotate(root);
    }

    //LR
    if (bf>1 && data > root->left->data)
    {
        printf("Appying LR Rotation \n");
        root->left = right_rotate(root->left);
        return left_rotate(root);
    }

    //RL
    if (bf < -1 && data < root->right->data) 
    {
    printf("Applying RL Rotation \n");
    root->right = left_rotate(root->right);
    return right_rotate(root);
    }

    return root;
}


void free_tree (node * root)
{
    if (root==NULL)
    {
        return;
    }
    
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

void choice(node * root)
{
    int choice=0,num=0;
    printf(" Enter 1 for Preorder \n Enter 2 for Inorder \n Enter 3 for Postorder \n Enter 4 to Insert \n Enter 0 to Exit \n");

    while (true)
    {
    
    printf("Enter choice \n");
        scanf("%d",&choice);
        if (choice==0)
        {
            printf("\nGoodbye\n");
            break;
        } 
    switch (choice)
    {
    case 1:
        {
            printf("Preorder Is: \n");
            preorder(root);
            printf("\n\n");
            break;
        }
    case 2:
        {
            printf("Inorder Is: \n");
            inorder(root);
            printf("\n\n");
            break;
        }
    case 3:
        {
            printf("Postorder Is: \n");
            postorder(root);
            printf("\n\n");
            break;
        }
    case 4:
        {
            printf("Enter number to Insert \n");
            scanf("%d", &num);
            root=insert(root,num);
            printf("After Insertion is complete: \n");
            preorder_with_bal(root);
            printf("\n\n");
            break;
        }
    default:
        {   
            printf("USER IS AN IDTOT!");
            break;
        }
    }
}
}

int main(int argc, char const *argv[])
{
    node * root =NULL;
    choice(root);
    free_tree(root);
    return 0;
}