#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node * next;
};

void print(struct node * head)
{
    struct node * ptr = head;
    do
    {
        printf("%d \n",ptr->data);
        ptr = ptr->next;
    }
    while (ptr!=head);
    printf("\n\n");
    free(ptr);
    
}

int main(int argc, char const *argv[])
{
    struct node * head = (struct node*)malloc(sizeof(struct node));
    struct node * first = (struct node*)malloc(sizeof(struct node));
    struct node * second =(struct node*) malloc(sizeof(struct node));

    head->data = 5;
    head->next= first;

    first->data=6;
    first->next = second;

    second->data = 7;
    second->next = head;

    print(head);

    return 0;
}