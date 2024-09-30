#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct node
{
    char data;
    node * left, * right;
}node;

typedef struct stack
{
    int top=-1;
    //array of node pointers
    node * * arr;
}stack;

int main(int argc, char const *argv[])
{
    stack * myst= (stack *)malloc(5 *sizeof(stack));
    return 0;
}
