#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct node
{
    int data;
    struct node * left;
    struct node * right;
}node;


void preorder(node * root)
{
    if (root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
    
}

void inorder(node * root)
{
    if (root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
    
}

void inorder_print_children(node * root)
{
    if (root!=NULL)
    { 
        if (root->left!=NULL)
        {
            printf("Left child of %d is %d \n",root->data ,root->left->data);
        }
        inorder(root->left);
        printf("%d \n",root->data);
        if (root->right!=NULL)
        {
            printf("Right child of %d is %d \n",root->data ,root->right->data);
        }
        inorder(root->right);
    }
    
}

void postorder(node * root)
{
    if (root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
    
}

node * create_node(int d)
{
    node * ptr = (node * ) malloc(sizeof(node));
    ptr->left=NULL;
    ptr->right=NULL;
    ptr->data=d;
    return ptr;
}


void insert(node * root , int data)
{
    node * prev=NULL;
    node * n= create_node(data);
    while (root!=NULL)
    {
        prev=root;
        if (root->data==data)
        {
            //duplicate
            return;
        }
        else if (data < root->data)
        {
            root=root->left;
        }
        else 
        {
            root=root->right;
        }        
    }

    if (prev->data > data)
    {
        //insert left , root is now leaf
        printf("The left node of %d is %d \n", prev->data , data);
        prev->left=n;
    }
    else
    {
        printf("The Right node of %d is %d \n", prev->data , data);
        prev->right=n;
    }
}

node * in_order_predecessor(node * root)
{
    // give rightmost value of left subtree
    root=root->left;
    while (root->right!=NULL)
    {
        root=root->right;
    }
    return root;
}

node * in_order_successor(node * root)
{
    //give leftmost val of right subtree
    root=root->right;
    while (root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}

node * delete(node * root , int value)
{
    node * ipre=NULL;
    if (root==NULL)
    {
        return NULL;
    }

    // no children
    if (root->left==NULL && root->right==NULL)
    {
        // parent ka must be set to null na?
        free(root);
        return NULL;
    }
    
    //recursive left and right
    if (root->data > value)
    {
        root->left = delete(root->left,value);
    }
    else if (root->data < value)
    {
        root->right=delete(root->right,value);
    }
    else
    {
        // we are at node
        // find the inorder predeccsor or successor
        
        //assume inorder predecessor
        ipre=in_order_predecessor(root);
        root->data=ipre->data;
        root->left= delete(root->left , ipre->data);
    }
    printf("Deleting %d \n",root->data);
    return root;
}

void choice(node * root)
{
    int choice=0,num=0;
    printf(" Enter 1 for Preorder \n Enter 2 for Inorder \n Enter 3 for Postorder \n Enter 4 to Insert \n Enter 5 to delete \n Enter 6 to print Inorder with Children \n Enter 0 to Exit \n");

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
            insert(root,num);
            printf("\n\n");
            break;
        }
    case 5:
        {
            printf("Enter number to Delete \n");
            scanf("%d", &num);
            delete(root,num);
            printf("\n\n");
            break;
        }
    case 6:
        {
            printf("Inorder with children is: \n");
            inorder_print_children(root);
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
    int num=0;
    printf("Enter root node: \n");
    scanf("%d", &num);
    node * root = create_node(num);
    choice(root);
    return 0;
}

