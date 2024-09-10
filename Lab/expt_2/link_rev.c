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
                // Swapping data if the current node has a greater value than the next node
                k = temp1->data;
                temp1->data = temp2->data;
                temp2->data = k;
            }
            temp1 = temp2;
            temp2 = temp2->next;
        }
    }
    //printf("Sorted Are: \n\n");
    //display(head);
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
  //printf("REMOVED ARE: \n\n");
  //display(head);
  return head;
}

void choice(struct node * head)
{
    int choice=0;
    printf("Welcome to choice \n Enter 1 to print \n enter 2 to insert \n enter 3 to sort \n enter 4 to remove duplicates \n enter 0 to end\n");
    int num=0;
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
            printf("Enter number to insert ");
            scanf("%d",&num);
            insert_at_start(head,num);
            break;
        case 3:
            sort(head);
            break;
        case 4:
            remov_dupli(head);
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

/*
    insert_at_start(head,5);
    insert_at_start(head,1);
    insert_at_start(head,1);
    insert_at_start(head,3);
    insert_at_start(head,8);
    insert_at_start(head,8);
    insert_at_start(head,2);
    display(head);
    sort(head);
    remov_dupli(head);
*/
    return 0;
}
