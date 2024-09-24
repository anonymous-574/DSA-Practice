#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

void print(struct node * ptr)
{
    while(ptr!= NULL)
    {
        printf("%d \n",ptr->data);
        ptr = ptr->next;
    }
    printf("\n\n");
}

struct node* insert_at_begin(struct node * old_head, int d)
{
    struct node * new_head = malloc(sizeof(struct node));
    new_head->data=d;
    new_head->next = old_head;

    // new head returned to start a new chain
    return new_head;
}

struct node* insert_at_index(struct node * head, int d, int index)
{
    struct node * ptr_insert = malloc(sizeof(struct node));
    ptr_insert->data=d;

    // make a temporary variable to hold location of current node
    // dont modify the head
    struct node * ptr =head;
    //go to just before the index where we want to place
    for (int i = 0; i < index-1; i++)
    {
        ptr= ptr->next;
    }
    ptr_insert->next=ptr->next;
    ptr->next=ptr_insert;

    // return the original head (now its chain points to new node)
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

struct node * insert_at_pos (struct node* head , struct node * prev_node , int d)
{
    struct node * new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data=d;
    new_node->next=prev_node->next;
    prev_node->next=new_node;
    return head;
}

struct node* delete_at_begin(struct node * old_head)
{
    struct node* temp_head = old_head;
    old_head = old_head->next;
    free(temp_head);
    return old_head;
}

struct node* delete_at_index(struct node * head , int index)
{
    struct node * ptr = head;

    for (int i = 0; i < index-1; i++)
    {
        ptr= ptr->next;
    }
    struct node * q = ptr->next;
    ptr->next = q->next;
    free(q);
    return head;
}

struct node* delete_at_key(struct node * head , int value)
{
    /*
    struct node * ptr = head;
    int length=0;
    while (ptr!=NULL)
    {
        ptr=ptr->next;
        if (ptr->data==value)
        {
            break;
        }
        length++;
    }
    ptr=head;
    for (int i = 0; i < length; i++)
    {
        ptr= ptr->next;
    }
    struct node * q = ptr->next;
    ptr->next = q->next;
    free(q);
    */
   struct node * ptr = head->next;
   struct node * prev = head;

   while (ptr->next!=NULL)
   {
    if (ptr->data==value)
    {
        break;
    }
    ptr=ptr->next;
    prev=prev->next;
   } 

   prev->next = ptr->next;
   free(ptr);
   return head;
}

struct node* delete_at_end(struct node * head)
{
    struct node * ptr1 = head;
    struct node * ptr2 = head->next;
    while(ptr2->next!= NULL)
    {
        ptr2 = ptr2->next;
        ptr1= ptr1->next;
    }

    
    ptr1->next= NULL;
    free(ptr2);
    return head;

}

struct node* reverseList(struct node* head) {

    // Initialize three pointers: curr, prev and next
    struct node *curr = head, *prev = NULL, *next;

    // Traverse all the nodes of Linked List
    while (curr != NULL) {

        // Store next
        next = curr->next;

        // Reverse current node's next pointer
        curr->next = prev;

        // Move pointers one position ahead
        prev = curr;
        curr = next;
    }

    // Return the head of reversed linked list
    return prev;
}

int main(int argc, char const *argv[])
{
    //head node
    struct node *head = (struct node*)malloc(sizeof(struct node));
    struct node *second = (struct node*)malloc(sizeof(struct node));
    struct node *third = (struct node*)malloc(sizeof(struct node));

    head->data = 11;
    head->next = second;

    second->data=12;
    second->next=third;

    third->data=66;
    third->next=NULL;
    print(head);
    head = insert_at_begin(head , 55);
    print(head);
    head = insert_at_index(head , 374 , 1);
    print(head);
    head = insert_at_end(head , 847);
    print(head);
    //head = delete_at_begin(head);
    //print(head);
    //head = delete_at_index(head , 1);
    //print(head);
    head = delete_at_end(head);
    print(head);
    head = insert_at_end(head , 99);
    print(head);
    head = insert_at_end(head , 91);
    print(head);
    head = delete_at_key(head , 66);
    print(head);
    return 0;
}
