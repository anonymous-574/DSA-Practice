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
    node * * arr;
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

    stack * s= (stack *)malloc(size *sizeof(stack));
    s->size=size;
    //printf("HI");
    for (int i = 0; i < 10; i++)
    {
        printf("HI? ");
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
            op->left=n1;
            op->right=n2;
            push(s,op);
        }   
    }
    
    node * output =pop(s);
    if (!is_empty_st(s))
    {
        printf("Input is wrong");
        return NULL;
    }
    printf("Hello");
    return output;
}

int main(int argc, char const *argv[])
{
    string input;

    //printf("Enter String: \n");
    //cin>>input;

    input="ab*c/ef/g*+k+xy*-";
    node * root = postfix_to_xt(input);
    //printf("\n\n\n");
    printf("\n\n HI hello");
    inorder(root);
    return 0;
}
