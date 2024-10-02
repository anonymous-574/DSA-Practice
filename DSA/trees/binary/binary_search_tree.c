#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

int arr[50];
int i=0;
void is_sorted_arr(struct node * root)
{
    if (root!=NULL)
    {
        is_sorted_arr(root->left);
        arr[i]=root->data;
        i++;
        is_sorted_arr(root->right);
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

struct node * prev=NULL;
struct node * search_for_l_r(struct node * root, int key)
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
        prev=root;
        search(root->left,key);
    }
    else
    {
        prev=root;
        search(root->right,key);
    }
} 
// this function returns the NODE that is found 

// in main (or a different function)
/*
    struct node * key = search_for_l_r(root , key);
    
    if (key==NULL)
    {
    printf("NOT FOUND");
    }
    if ( prev = NULL)
    {
    printf("ROOT node")
    }

    if (prev->left = key)
    {
    printf("LEFT");
    }
    else
    {
    printf("RIGHT")
    }

*/


bool is_bst(struct node * root)
{
    //use inorder traversal
    //if its ascending order then yes
    static struct node * prev=NULL;
    if (root!=NULL)
    {
        //preorder(root->left);
        if (!is_bst(root->left))
        {
            return false;
        }
        if (prev!=NULL && root->data <=prev->data)
        {
            return false;
        }
        prev=root;
        return is_bst(root->right);
    }
    return true;
}

void insert(struct node * root , int data)
{
    struct node * prev=NULL;
    struct node * n= create_node(data);
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
        prev->left=n;
    }
    else
    {
        prev->right=n;
    }
}

struct node * in_order_predecessor( struct node * root)
{
    // give rightmost value of left subtree
    root=root->left;
    while (root->right!=NULL)
    {
        root=root->right;
    }
    return root;
}

struct node * getSuccessor(struct node* root)
{
    //give leftmost value of right subtree
    root = root->right;
    while (root->left != NULL)
        root = root->left;
    return root;
}

struct node * delete(struct node * root , int value)
{
    struct node * ipre=NULL;
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
    printf("Deleting %d",root->data);
    return root;
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
    struct node * root =create_node(10);
    insert(root,5);
    insert(root,6);
    insert(root,20);
    insert(root,14);

    printf("IS_bst: %d \n" ,is_bst(root));
    preorder(root);
    printf("\n\n\n");
    postorder(root);
    printf("\n\n\n");
    inorder(root);
    printf("\n\n\n");
    is_sorted_arr(root);

    for (int j = 0; j < 5; j++)
    {
        printf("%d \n", arr[j]);
    }
    

    free_tree(root);
    return 0;
}
