#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node * prev;
}node;

void display (node * head)
{
    node * temp = head;
    printf("\n");
    while (temp->next!=NULL)
    {
        temp=temp->next;
        printf("%d ->", temp->data);
    }
    printf(" NULL \n");
    printf("\n\n");
}

int length (node * head)
{
    if (head==NULL)
    {
        return 0;
    }
    return (1+length(head->next));
}

node * get_node(int data)
{
    node * new = (node * ) malloc(sizeof(node));
    new->data=data;
    new->next=NULL;
    new->prev=NULL;
    return new;
}

node * insert_at_start (node * head , int data)
{
    node * new = get_node(data);
    head->next->prev=new;
    new->next=head->next;
    head->next=new;
    display(head);
    return head;
}

node * insert_at_end (node * head , int data)
{
    node * new = get_node(data);
    node * temp=head;

    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=new;
    new->prev=temp;
    display(head);
    return head;
}

// delete at end , left specific

node * delete_at_end (node * head )
{
    node * temp=head;

    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    //temp is now last node;
    temp->prev->next=NULL;
    free(temp);
    display(head);
    return head;
}

node * delete_at_left_of_data(node * head , int value)
{
    node * temp=head;
    while (temp->next!=NULL && temp->data!=value)
    {
        temp=temp->next;
    }
    node * to_del = temp->prev;
    //temp is now the node
    // delete the node to the left of it
    temp->prev->prev->next=temp;
    temp->prev = temp->prev->prev;
    free(to_del);
    display(head);
    return head;

}

void menu (node * head)
{
    int choice=0;
    printf("Welcome to choice \n Enter 1 to print \n Enter 2 to insert at start \n Enter 3 to insert at end \n Enter 4 to delete at end \n Enter 5 to delete at left of data \n Enter 6 to print length of Doubly LL \n Enter 0 to end\n");
    int num=0,len=0;
    while (true)
    {
        printf("Enter choice \n");
        scanf("%d",&choice);
        if (choice==0)
        {
            printf("Goodbye");
            break;
        } 

        switch (choice)
        {
        case 1:
            display(head);
            break;
        case 2:
            printf("Enter number to insert at start ");
            scanf("%d",&num);
            insert_at_start(head,num);
            break;
        case 3:
            printf("Enter number to insert at end ");
            scanf("%d",&num);
            insert_at_end(head,num);
            break;
        case 4:
            delete_at_end(head);
            break;
        case 5:
            printf("Enter number to delete at left of ");
            scanf("%d",&num);
            delete_at_left_of_data(head,num);
            break;
        case 6:
            len = length(head)-1;
            printf("Length is %d \n\n", len);
            break;
        default:
            printf("USER IS AN IDIOT! ");
            break;
        }
    }
}

int main(int argc, char const *argv[])
{
    node * head = (node * ) malloc(sizeof(node));

    int num=0;
    printf("Enter 1 manditory node: ");
    scanf("%d", &num);
    node * n1 = get_node(num);
    head->next=n1;

    menu(head);
    return 0;
}