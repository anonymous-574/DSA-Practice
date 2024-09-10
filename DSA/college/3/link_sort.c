#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node * next;
};

void display(struct node * head)
{
    printf("\n\n");
    struct node * temp= head->next;
    
    while (temp!=NULL)
    {
        printf("%d \n",temp->data);
        temp=temp->next;
    }
}

int tell_size(struct node * head)
{
    int size=0;
    struct node * temp= head->next;
    
    while (temp!=NULL)
    {
        size++;
        temp=temp->next;
    }
    return size;
}

struct node * insert_at_start(struct node * head,int d)
{
    struct node * new = (struct node * ) malloc(sizeof(struct node));
    new->next=head->next;
    head->next=new;
    new->data=d;
    return head;
}

struct node* insert_at_index(struct node * head, int d, int index)
{
    struct node * ptr_insert = malloc(sizeof(struct node));
    ptr_insert->data=d;

    struct node * ptr =head;
    //go to just before the index where we want to place
    for (int i = 0; i < index-1; i++)
    {
        ptr= ptr->next;
    }
    ptr_insert->next=ptr->next;
    ptr->next=ptr_insert;
    return head;
    
}

struct node* insert_at_end(struct node * head, int d)
{
    struct node * new_end = malloc(sizeof(struct node));
    struct node * ptr =head;
    new_end->data=d;

    while(ptr->next!= NULL)
    {
        ptr = ptr->next;
    }
    ptr->next=new_end;
    new_end->next=NULL;
    return head;
}

struct node * sort(struct node * head)
{
    int size=tell_size(head);
    struct node* temp1=NULL;
    struct node* temp2=NULL;
    int k=0;
    for (int i = size - 2; i >= 0; i--) {
        temp1 = head->next;
        temp2 = temp1->next;
        for (int j = 0; j <= i; j++) {
            if (temp1->data > temp2->data) {
                k = temp1->data;
                temp1->data = temp2->data;
                temp2->data = k;
            }
            temp1 = temp2;
            temp2 = temp2->next;
        }
    }
    return head;
}




struct node * remov_dupli(struct node * head)
{
  struct node * temp1=head->next;
  while (temp1->next!=NULL)
  {
    if (temp1->data==temp1->next->data)
    {
        struct node * hold_temp=temp1->next;
        temp1->next=temp1->next->next;
        free(hold_temp);
    }
    temp1=temp1->next;
  }
  return head;
}

void choice(struct node * head)
{
    int choice=0;
    printf("Welcome to choice \n Enter 1 to print \n enter 2 to insert at start \n enter 3 to sort \n enter 4 to remove duplicates \n enter 5 to insert at position \n enter 6 to insert at end\n enter 0 to end\n");
    int num=0,idx=0;
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
            sort(head);
            break;
        case 4:
            remov_dupli(head);
            break;
        case 5:
            printf("Enter number to insert at middle");
            scanf("%d",&num);
            printf("Enter Index: \n");
            scanf("%d",&idx);
            insert_at_index(head ,num,idx);
            break;
        case 6:
            printf("Enter number to insert at end ");
            scanf("%d",&num);
            insert_at_end(head,num);
            break;
        default:
            printf("USER IS AN IDIOT!");
            break;
        }
    }
    

}

int main(int argc, char const *argv[])
{
    struct node * head = (struct node * ) malloc(sizeof(struct node));
    struct node * first = (struct node * ) malloc(sizeof(struct node));
    head->next=first;
    int no1=0;
    printf("Enter first element (manditory): \n");
    scanf("%d",&no1);
    first->data=no1;
    first->next=NULL;
    choice(head);
    return 0;
}