

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct stack
{
    int top;
    int size;
    char * arr;
};

bool is_empty(struct stack * s)
{
    if (s->top==-1)
    {
        return true;
    }

    return false;
}

bool is_full (struct stack *s)
{
    // array starts from [0]
    if (s->top ==(s->size-1))
    {
        return true;
    }
    
    return false;
}

void push(struct stack * s1, char data)
{
    if (is_full(s1))
    {
        printf("FAIL");
        return;
    }
    s1->top++;
    s1->arr[s1->top]=data;
}

char pop (struct stack * s)
{
    if (is_empty(s))
    {
        printf("FAIL");
        return 'f';
    }
    
    return s->arr[s->top--];
}

int match ( char a , char b )
{
    if (a =='[' && b == ']')
    {
        return 1;
    }
    else if (a=='(' && b ==')')
    {
        return 1;
    }
    else if (a=='{' && b =='}')
    {
        return 1;
    }
    else
    {
        return 0;
    }  
}

bool isValid(char* s) 
{
    struct stack *s1= (struct stack *) malloc(sizeof (struct stack));
    s1->size=10000;
    s1->arr = (char *) malloc(s1->size*sizeof(char));
    s1->top=-1;

    char* str = s;
    char pop_res='a';
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i]=='(' ||str[i]=='[' || str[i]=='{' )
        {
            push(s1 , str[i]);
        }
        else if (str[i]==')' ||str[i]==']' || str[i]=='}')
        {
            pop_res = pop(s1);
            
            if (pop_res =='f')
            {
                return false;
            }
            if (!match (pop_res , str[i]))
            {
               return false;
            }
            
        }
    }

    if (!is_empty(s1) )
    {
        return false;
    }
    else
    {
        return true;       
    }
    
}