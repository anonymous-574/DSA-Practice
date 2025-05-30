#include <iostream>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
using namespace std;

typedef struct node
{
    char data;
    node * left, * right;
}node;

void inorder (node * root)
{
    if (root!=NULL)
    {
        inorder(root->left);
        printf("%c ",root->data);
        inorder(root->right);
    }
    
}

node * create_node(char d)
{
    struct node * ptr = (struct node * ) malloc(sizeof(struct node));
    ptr->left=NULL;
    ptr->right=NULL;
    ptr->data=d;
    return ptr;
}

typedef struct stack
{
    int top=-1;
    int size=0;
    //array of node pointers
    //node * * arr;
    node * arr[20];
}stack;

bool is_empty_st(stack * s)
{
    if (s->top==-1)
    {
        return true;
    }

    return false;
}

bool is_full (stack *s)
{
    // array starts from [0]
    if (s->top ==(s->size-1))
    {
        return true;
    }
    
    return false;
}

void push(stack * s1,node * data)
{
    if (is_full(s1))
    {
        printf("FAIL");
        return;
    }
    s1->top++;
    s1->arr[s1->top]=data;
}

node * pop (stack * s)
{
    if (is_empty_st(s))
    {
        printf("FAIL");
        return NULL;
    }
    
    return s->arr[s->top--];
}

bool is_operator (char op)
{
    if (op=='+' ||op=='-' ||op=='*' ||op=='/')
    {
        return true;
    }
    else
    {
        return false;
    }
}

node * postfix_to_xt(string input)
{
    int size=0;
    //printf("Enter size of stack: \n");
    //scanf("%d" , &size);

    size=20;

    stack * s= (stack *)malloc(sizeof(stack));
    s->size=size;
    //s->arr = (node * *) malloc(size*sizeof(node*));
    
    //printf("HI");
    for (int i = 0; i < input.length(); i++)
    {
        if (!is_operator(input[i]))
        {
            node * temp = create_node(input[i]);
            push(s,temp);
        }
        else
        {
            node * op = create_node(input[i]);
            node * n1 = pop(s);
            node * n2 = pop(s);
            op->right=n1;
            op->left=n2;
            push(s,op);
        }   
    }
    
    node * output =pop(s);
    pop(s);
    if (is_empty_st(s))
    {
        printf("Hello Done");
        return output;
    }
    printf("Input is wrong");
    return NULL;
}

int main(int argc, char const *argv[])
{
    string input;

    //printf("Enter String: \n");
    //cin>>input;

    input="231*+9-";
    node * root = postfix_to_xt(input);
    //printf("\n\n\n");
    inorder(root);
    return 0;
}
