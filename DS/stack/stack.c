#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef  struct stack
{
    int top;
    int size;
    int * arr;
}stack;

bool is_empty(  stack * s)
{
    if (s->top==-1)
    {
        return true;
    }

    return false;
}

bool is_full (  stack *s)
{
    // array starts from [0]
    if (s->top ==(s->size-1))
    {
        return true;
    }
    
    return false;
}

void push(  stack * s1, int data)
{
    if (is_full(s1))
    {
        printf("FAIL");
        return;
    }
    s1->top++;
    s1->arr[s1->top]=data;
}

int pop (  stack * s)
{
    if (is_empty(s))
    {
        printf("FAIL");
        return -1;
    }
    
    return s->arr[s->top--];
}

int peek (  stack * s , int idx)
{
    if (s->top -idx +1<0)
    {
        printf("INVALID");
        return -1;
    }
    
    
    return s->arr[s->top-idx+1];
}

int stack_top (  stack *s)
{
    return s->arr[s->top];
}

int stack_bottom (  stack *s)
{
    return s->arr[0];
}

int main(int argc, char const *argv[])
{
      stack *s= (  stack *) malloc(sizeof (  stack));
    s->size=10;
    s->arr = (int *) malloc(s->size*sizeof(int));
    s->top=-1;

    
    push(s , 1);
    push(s , 2);
    push(s,3);
    
    int no = pop(s);
    printf("%d \n", no);

    int peek1 = peek(s , 1);
    printf("%d \n", peek1);
    return 0;
}
