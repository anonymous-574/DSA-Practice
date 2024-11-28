#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct link
{
    int data;
    struct link * next;
};

void print (struct link * top)
{
    while (top!=NULL)
    {
        printf("%d \n",top->data);
        top=top->next;
    }
    printf("\n\n");
}

bool is_empty (struct link * top)
{
    if (top==NULL)
    {
        return true;
    }
    return false;
}

bool is_full (struct link * top)
{
    // allocate a node
    // if its null then memory is full
    struct link * s =(struct link*) malloc(sizeof(struct link));

    if (s==NULL)
    {
        free(s);
        return true;
    }
    free(s);
    return false;
}


struct link* push(struct link * top, int d)
{
    if (is_full(top))
    {
        printf("FULL");
        return top;
    }
    struct link * new_end =(struct link *) malloc(sizeof(struct link));
    if (new_end==NULL)
    {
        printf("STACK OVERFLOW");
        return top;
    }

    new_end->data = d;
    new_end->next=top;
    top=new_end;
    return top;
}

int pop(struct link ** top) // delete at end
{
    if (is_empty(*top))
    {
        printf("STACK UNDERFLOW");
        return -1;
    }
    struct link * ptr1 = *top;
    *top = (*top)->next;
    int x = ptr1->data;
    free(ptr1);
    return x;
}

int peek(struct link *top , int idx)
{
    struct link * temp = top;
    //not equal to null check if index is larger than stack size
  for (int i = 0; i < (idx-1 && temp!=NULL); i++)
  {
    temp=temp->next;
  }
  
  if (temp==NULL)
  {
    printf("FAIL");
    return -1;
  }
  else
  {
    // only do this if the pointer actually exists
    int data = temp->data;
    free(temp);
    return data;
  }
}


int stack_top (struct link * top)
{
    return top->data;
}

int stack_bottom (struct link * top)
{
    while (top->next!=NULL)
    {
        top=top->next;
    }
    return top->data;
}

int main(int argc, char const *argv[])
{
    struct link* top =NULL;
    top = push(top , 4);
    top = push(top , 5);
    top = push(top , 6);
    top = push(top , 7);
    int data= pop(&top);
    printf("POPPED %d \n",data);
    print(top);   
    data = peek(top, 1);
    printf("peeked %d \n",data);
    return 0;
}
