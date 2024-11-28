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
    //strdup to because we are sending pointer . What if the pointer is gone? i.e data is overwritten
    //YES THIS IS NECESSARY
    s1->arr[s1->top]=strdup (data);
}

char * pop (struct stack * s)
{
    if (is_empty(s))
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

void print_st(struct stack * s1)
{
    for (int i = 0; i < s1->top; i++)
    {
        printf("%s \n",s1->arr[i]);
    }
    
}

void evaluate_postfix(char * op,int len)
{
    struct stack * s = (struct stack *) malloc(sizeof(struct stack));
    s->size=10;
    s->arr = (char**)malloc(s->size * sizeof(char*));
    //make size of each string 10 characters
    for (int i = 0; i < s->size; i++)
    {
        s->arr[i]=(char*)malloc(s->size*sizeof(char));
    }
    s->top=-1;

    char temp[10];
    temp[0] ='\0';
    
    for (int i = 0; i < len; i++)
    {
        if (!is_operator(op[i]))
        {
            char str[2] = {op[i], '\0'};
            push(s,str);
        }
        else
        {
            char *s1=pop(s);
            char *s2=pop(s);
            strcat(temp,s2);
            char str[2] = {op[i], '\0'};
            strcat(temp,str);
            strcat(temp,s1);

            printf("\n temp: %s",temp);
            push(s,temp);  
            temp[0]='\0';
        }
    }
    printf("\n Final expression Postfix: \n");
    printf("%s \n",pop(s));
    printf("\n\n\n"); 
}

void evaluate_prefix(char * op,int len)
{
    struct stack * s = (struct stack *) malloc(sizeof(struct stack));
    s->size=10;
    s->arr = (char**)malloc(s->size * sizeof(char*));
    //make size of each string 10 characters
    for (int i = 0; i < s->size; i++)
    {
        s->arr[i]=(char*)malloc(s->size*sizeof(char));
    }
    s->top=-1;

    char temp[10];
    temp[0] ='\0';

    for (int i = len-1; i >=0; i--)
    {
        if (!is_operator(op[i]))
        {
            char str[2] = {op[i], '\0'};
            push(s,str);
        }
        else
        {
            strcat(temp,pop(s));
            char str[2] = {op[i], '\0'};
            strcat(temp,str);
            strcat(temp,pop(s));

            printf("\n temp: %s",temp);
            push(s,temp);  
            temp[0]='\0';
        }
    }
    printf("\n Final expression Prefix: \n");
    printf("%s \n",pop(s));
    
}


int main(int argc, char const *argv[])
{
    char * op = "ab+";
    evaluate_postfix(op,3);
    char * op1="+ab";
    evaluate_prefix(op1,3);
    return 0;
}