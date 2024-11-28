#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct stack
{
    int top;
    int size;
    char * * arr;
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

void push(struct stack * s1, char * data)
{
    if (is_full(s1))
    {
        printf("FAIL");
        return;
    }
    s1->top++;
    s1->arr[s1->top]=data;
}

char * pop (struct stack * s)
{
    if (is_empty(s))
    {
        printf("FAIL");
        return "F";
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


void evaluate_postfix(char * op,int len)
{
    struct stack * s = (struct stack *) malloc(sizeof(struct stack *));
    s->size=10;
    s->arr = (char**)malloc(s->size * sizeof(char*));
    //make size of each string 10 characters
    for (int i = 0; i < s->size; i++)
    {
        s->arr[i]=(char*)malloc(s->size*sizeof(char));
    }
    s->top=-1;

    printf("%d",len);
    char temp[10];
    temp[0] ='\0';
    
    for (int i = 0; i < len; i++)
    {
        if (!is_operator(op[i]))
        {
            push(s,&op[i]);
        }
        else
        {
            strcat(temp,pop(s));
            strcat(temp,&op[i]);
            strcat(temp,pop(s));
            push(s,temp);
            temp[0]='\0';
        }
    }
    printf("HI print here");
    printf("%s \n",pop(s));
    
    
}

int main(int argc, char const *argv[])
{
    char * op = "ab+";
    printf("%s \n",op);
    printf("HI");
    evaluate_postfix(op,3);
    printf("BYE");
    return 0;
}