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
        return -1;
    }
    
    return s->arr[s->top--];
}

bool is_operator (char op)
{
    if (op=='+' ||op=='-' ||op=='*' ||op=='/' || op=='('||op==')')
    {
        return true;
    }
    else
    {
        return false;
    }
}

int weight_of_operator (char op)
{
    if (op=='+' ||op=='-')
    {
        return 1;
    }
    else if (op=='*' ||op=='/')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

char * in_to_po (char* imput)
{
    struct stack * s = (struct stack *) malloc(sizeof(struct stack));
    s->size=10;
    s->arr = (char *) malloc(s->size*sizeof(char));
    s->top=-1;

    //output string
    char * output = (char *)malloc((strlen(imput)+1)*sizeof(char));

    int i=0,j=0;

    while (imput[i]!='\0')
    {
        if (!is_operator(imput[i]))
            {
                output[j]=imput[i];
                i++;
                j++;
            }
        else
        {
            if (weight_of_operator(imput[i])> weight_of_operator(s->arr[s->top]))
                {
                push(s , imput[i]);
                i++;
                }
            else
                {
                output[j]=pop(s);
                j++;
                }
        }
        
    }
    while (!is_empty(s))
        {
        output[j]=pop(s);
        j++;
        }
    output[j]='\0';
    free(s->arr);
    free(s);
    return output;
}

char * in_to_pre (char* input)
{
    struct stack * s = (struct stack *) malloc(sizeof(struct stack));
    s->size=10;
    s->arr = (char *) malloc(s->size*sizeof(char));
    s->top=-1;

    //output string
    char * output = (char *)malloc((strlen(input)+1)*sizeof(char));
    int j=strlen(input)-2;    
    for (int i = strlen(input)-1; i >= 0; i--)
    {
        if (!is_operator(input[i]))
        {
            output[j]=input[i];
            j--;
        }
        else if(input[i]==')')
        {
            push(s,input[i]);
        }
        else if (input[i]=='(')
        {
            while (s->top!=')')
            {
                output[j]=pop(s);
                j--;
            }   
        }
        else
        {
            //we have an operator
            if (weight_of_operator(input[i])>= weight_of_operator(s->arr[s->top]))
            {
                push(s , input[i]);
            }
            else
            {
                output[j]=pop(s);
                j--;
            }
            

        }  
    }
    while (!is_empty(s))
        {
        output[j]=pop(s);
        j--;
        }
    output[strlen(input)-1]='\0';
    return output;
    
}

int main(int argc, char const *argv[])
{
    char * op = in_to_po("1+2*3-4");
    printf("%s ",op);
    char * op1 = in_to_pre("1+2*3-4");
    printf("%s ",op1);    
    return 0;
}
