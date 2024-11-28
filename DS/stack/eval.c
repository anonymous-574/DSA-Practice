#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stack
{
    int top,size;
    int * arr;
}stack;

bool is_full(stack * s)
{
    if (s->top==s->size-1)
    {
        return true;
    }
    return false;
}

bool is_empty(stack * s)
{
    if (s->top==-1)
    {
        return true;
    }
    return false;
}

void push(stack * s, int val)
{
    if (is_full(s))
    {
        printf("Stack overflow (Tm)");
        return;
    }
    s->arr[++s->top]=val;
}

int pop(stack *s)
{
    if (is_empty(s))
    {
        printf("Empty");
        return -1;
    }
    int val=s->arr[s->top];
    s->top--;
    return val;
}

bool is_operator(char o)
{
    if (o=='+'||o=='-'||o=='*'||o=='/')
    {
        return true;
    }
    return false;
}

int calc(int op1,int op2,char opr)
{
    if (opr=='+')
    {
        return op2+op1;
    }
    else if (opr=='-')
    {
        return op2-op1;
    }
    else if (opr=='*')
    {
        return op2*op1;
    }
    else if (opr=='/')
    {
        return op2/op1;
    }
    else
    {
        printf("Yo how did ya get here \n");
        return -1;
    }
    
    
    
}


void eval_postfix(char *input,int len)
{
    stack *s = (stack *)malloc(sizeof(stack));
    s->size=10;
    s->arr=(int *)malloc(s->size*sizeof(int));
    s->top=-1;


    for (int i = 0; i < len; i++)
    {
        if (!is_operator(input[i]))
        {
            push(s,input[i]-'0');
        }
        else
        {
            int op1=pop(s);
            int op2=pop(s);
            int calc_val=calc(op1,op2,input[i]);
            push(s,calc_val);
        }
    }
    int ans=pop(s);
    printf("Evaluated Postfix: %d \n",ans);
    free(s->arr);
    free(s);
}


void eval_prefix(char *input,int len)
{
    stack *s = (stack *)malloc(sizeof(stack));
    s->size=10;
    s->arr=(int *)malloc(s->size*sizeof(int));
    s->top=-1;


    for (int i = len-1; i >= 0; i--)
    {
        if (!is_operator(input[i]))
        {
            push(s,input[i]-'0');
        }
        else
        {
            int op2=pop(s);
            int op1=pop(s);
            int calc_val=calc(op1,op2,input[i]);
            push(s,calc_val);
        }
    }
    int ans=pop(s);
    printf("Evaluated Prefix: %d \n",ans);
}

int main(int argc, char const *argv[])
{
    char * op = "52+";
    eval_postfix(op,3);
    char* op1="+52";
    eval_prefix(op1,3);
    return 0;
}
