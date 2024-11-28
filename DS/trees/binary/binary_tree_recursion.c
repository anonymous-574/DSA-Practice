#include<stdio.h>
#include<stdlib.h>
int node = 0;
int leave = 0;
struct Node
{
    int data;
    char val;
    struct Node *left;
    struct Node *right;
};
struct pointstack
{
    struct Node* node;
    struct pointstack* next;
    struct pointstack* prev;
};
struct Node* pop(struct pointstack* top)
{
    struct Node* ret = top->node;
    top = top->prev;
    top->next == NULL;
    return ret;
}
void push(struct pointstack* top,struct Node* data)
{
    struct pointstack* newtop = (struct pointstack*)malloc(sizeof(struct pointstack));
    newtop->node = data;
    newtop->prev = top;
    top->next = newtop;
    top = newtop;
    printf("\n%c",top->node->val);
}
void inorderprint(struct Node* root)
{
    if(root->left!=NULL)
    {
        inorderprint(root->left);
    }
    printf("%d",root->data);
    printf("IN loop\n");
    if(root->right!=NULL)
    {
        inorderprint(root->right);
    }
    return;
}
void nodes(struct Node* root)
{
    node++;
    if(root->right!=NULL)
    {
        nodes(root->right);
    }
    if(root->left!=NULL)
    {
        nodes(root->left);
    }
}
void leaves(struct Node* root)
{
    if(root->left == NULL && root->right == NULL)
    {
        leave++;
    }
    else if(root->left == NULL)
    {
        leaves(root->right);
    }
    else if(root->right == NULL)
    {
        leaves(root->left);
    }
    else
    {
        leaves(root->left);
        leaves(root->right);
    }
}
void newinorderprint(struct Node* root) 
{ 
    if(root->left!=NULL) 
    { 
        newinorderprint(root->left); 
    } 
    printf("%c",root->val); 
    if(root->right!=NULL) 
    { 
        newinorderprint(root->right); 
    } 
    return; 
}
void printstack(struct pointstack* top) 
{ 
    newinorderprint(top->node); 
    printf(","); 
    if(top->next->next!=NULL) 
    { 
        printstack(top->next); 
    } 
}
void expr(char str[]) 
{ 
    struct Node *front,*back; 
    struct pointstack* top = (struct pointstack*)malloc(sizeof(struct pointstack)); 
    top->next = NULL; 
    for(int i = 0;str[i]!='\0';i++) 
    { 
        if(str[i]<'a'||str[i]>'z') 
        { 
            back = top->node; 
            top = top->next; 
            front = top->node; 
            top = top->next; 
            struct Node* join = (struct Node*)malloc(sizeof(struct Node)); 
            join->left = front; 
            join->right = back; 
            join->val = str[i]; 
            join->data = 0; 
            struct pointstack* newtop = (struct pointstack*)malloc(sizeof(struct pointstack)); 
            newtop->node = join; 
            newtop->next = top; 
            top = newtop; 
        } 
        else 
        { 
            struct Node* join = (struct Node*)malloc(sizeof(struct Node)); 
            join->left = NULL; 
            join->right = NULL; 
            join->val = str[i]; 
            join->data = 0; 
            struct pointstack* newtop = (struct pointstack*)malloc(sizeof(struct pointstack)); 
            newtop->node = join; 
            newtop->next = top; 
            top = newtop; 
        } 
        printf("\n"); 
        printstack(top); 
    } 
    struct Node* final = top->node; 
    printf("\n"); 
    newinorderprint(final); 
}
void level(int num,struct Node* root,int lev)
{
    if(root == NULL)
    {
        return;
    }
    if(root->data == num)
    {
        printf("\nLevel of %d:%d",num,lev);
        return;
    }
    level(num,root->right,lev+1);
    level(num,root->left,lev+1);
}
/*
void createbt(struct Node* root)
{
    int temp;
    printf("Enter Left Value of Node %d (Enter -1 to leave the node empty):",root->data);
    scanf("%d",&temp);
    if(temp!=-1)
    {
        struct Node* leftnode = (struct Node*)malloc(sizeof(struct Node));
        leftnode->data = temp;
        leftnode->val = '0';
        leftnode->left = NULL;
        leftnode->right = NULL;
        root->left = leftnode;
        createbt(root->left);
    }
    printf("Enter Right Value of Node %d (Enter -1 to leave the node empty):",root->data);
    scanf("%d",&temp);
    if(temp!=-1)
    {
        struct Node* rightnode = (struct Node*)malloc(sizeof(struct Node));
        rightnode->data = temp;
        rightnode->val = '0';
        rightnode->left = NULL;
        rightnode->right = NULL;
        root->right = rightnode;
        createbt(root->right);
    }
    
}
*/


void createbt(struct Node* root)
{
    int val1=-1;
    printf("Enter left child of %d",root->data);
    scanf("%d",&val1);
    if (val1!=-1)
    {
        struct Node * new = (struct Node *)malloc(sizeof(struct Node));
        new->data=val1;
        new->left=NULL;
        new->right=NULL;
        root->left=new;
        createbt(root->left);
    }

    printf("Enter right child of %d",root->data);
    scanf("%d",&val1);
    if (val1!=-1)
    {
        struct Node * new = (struct Node *)malloc(sizeof(struct Node));
        new->data=val1;
        new->left=NULL;
        new->right=NULL;
        root->right=new;
        createbt(root->right);
    }
    
}
void main()
{
    struct Node* root =(struct Node*)malloc(sizeof(struct Node));
    int temp;
    printf("Enter Value of root node:");
    scanf("%d",&temp);
    root->data = temp;
    root->right = NULL;
    root->left = NULL;
    createbt(root);
    /*
    inorderprint(root);
    nodes(root);
    leaves(root);
    printf("\nNodes:%d",node);
    printf("\nLeaves:%d",leave);
    level(91,root,0);
    expr("ab+cd-*");
    */
}