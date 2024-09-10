#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node * left;
    struct node * right;
};

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
        preorder(root->left);
        preorder(root->right);
        printf("%d \n",root->data);
    }
}

void inorder(struct node * root)
{
    if (root!=NULL)
    {
        preorder(root->left);
        printf("%d \n",root->data);
        preorder(root->right);
    }
}

struct node * create_node(int d)
{
    struct node * ptr = (struct node * ) malloc(sizeof(struct node));
    ptr->left=NULL;
    ptr->right=NULL;
    ptr->data=d;
    return ptr;
}

int main(int argc, char const *argv[])
{
    struct node * root =create_node(10);
    struct node * n1= create_node(3);
    struct node * n2= create_node(4);
    struct node * n3= create_node(5);
    struct node * n4= create_node(6);
    root->left=n1;
    root->right=n2;
    n1->left=n3;
    n1->right=n4;
    preorder(root);
    printf("\n\n\n");
    postorder(root);
    printf("\n\n\n");
    inorder(root);
    return 0;
}
