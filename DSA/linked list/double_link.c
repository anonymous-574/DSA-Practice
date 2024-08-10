#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node * next;
    struct node * prev;
};

void print(struct node * head)
{
    struct node * ptr = head;
    
    do
    {
        printf("%d \n",ptr->data);
        ptr=ptr->next;
    }
    while (ptr->next!=NULL);
    printf("%d \n",ptr->data);
    free(ptr);
}


int main(int argc, char const *argv[])
{
    
    struct node * head = (struct node * ) malloc (sizeof (struct node));
    struct node * second = (struct node * ) malloc (sizeof (struct node));
    struct node * third = (struct node * ) malloc (sizeof (struct node));

    head->data = 1;
    head->prev=NULL;
    head->next = second;
    
    second->data=2;
    second->prev=head;
    second->next=third;

    third->data=3;
    third->prev=second;
    third->next=NULL;

    print(head);
    return 0;
}
