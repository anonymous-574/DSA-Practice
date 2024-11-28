#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct node
{
    char data;
    struct node * left; 
    struct node * right;
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
    int top,size;
    struct node * * arr;
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
    printf("Pushing: %c \n", data->data);
}

node * pop (stack * s)
{
    if (is_empty_st(s))
    {
        return NULL;
    }
    node * temp = s->arr[s->top--];
    printf("Popping: %c \n", temp->data);
    return temp;
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

node * prefix_to_xt( char * input )
{
    int str_len = strlen(input); 

    stack * s= (stack *)malloc(sizeof(stack));
    s->top=-1;
    s->size=str_len;
    s->arr = (node * *)  malloc(str_len*sizeof(node *));
    
    for (int i = str_len-1; i >= 0; i--)
    {
        if (!is_operator(input[i]))
        {
            node * temp = create_node(input[i]);
            push(s,temp);
        }
        else
        {
            node * op = create_node(input[i]);
            printf("Operator is %c \n",op->data);
            node * n1 = pop(s);
            op->left=n1;
            printf("Left child of %c is: %c \n",op->data ,op->left->data);
            node * n2 = pop(s);
            op->right=n2;
            printf("Right child of %c is: %c \n",op->data, op->right->data);
            push(s,op);
        }   
    }
    
    printf("Root node is: \n");
    node * output =pop(s);
    pop(s);
    if (is_empty_st(s))
    {
        return output;
    }
    printf("Input is wrong");
    return NULL;
}

int evaluate(node * root)
{
    if (root->left==NULL && root->right==NULL)
    {
        return( (int) root->data -'0');
    }
    
    switch (root->data)
    {
    case'/':
            {
            return evaluate(root->left) / evaluate(root->right);      
            break;
            }
    case'*':
            {
            return evaluate(root->left) * evaluate(root->right);      
            break;
            }
    case'-':
            {
            return evaluate(root->left) - evaluate(root->right);      
            break;
            }
    case'+':
            {
            return evaluate(root->left) + evaluate(root->right);      
            break;
            }
    default:
            {
            printf("Acheivement Unlocked: How did we get here? \n");
            printf("Wrong operator or tree? \n");
            break;
            }
    }
}

int main(int argc, char const *argv[])
{
    char * input;
    int size;
    
    
    printf("Enter Size of String: \n");
    scanf("%d",&size);
    printf("Enter Preorder: \n");
    getchar();
    input=(char *) malloc(size*sizeof(char));
    scanf("%[^\n]%*c", input);
    input[size+1]='\0';
    
    //input="-+*12*/3523";
    //len=11
    node * root = prefix_to_xt(input);
    printf("\n\n\n Inorder is: \n");
    inorder(root);
    printf("\n\n\n");
    int ans =evaluate(root);
    printf("Value of Expression Tree is %d \n",ans);
    printf("\n\n\n");
    
    return 0;
}