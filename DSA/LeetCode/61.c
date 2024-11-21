#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

int size(struct ListNode* head)
{
    struct ListNode* temp=head;
    int size=0;
    while (temp!=NULL)
    {
        size++;
        temp=temp->next;
    }
    return size;
}

struct ListNode* rotateRight(struct ListNode* head, int k) {
    int size1=size(head);

    struct ListNode* last = head;
    struct ListNode* second_last = head;

    if (size1==0)
    {
        return head;
    }
    
    //for this many times (this is the logic dont ask)
    //it is circular
    for (int i =1; i <= k%size1; i++)
    {
        //travel to second last and last node
        while (last->next!=NULL)
        {
            second_last=last;
            last=last->next;
        }
        //add last node to front
        last->next=head;
        head=last;
        second_last->next=NULL;  
    }
    return head;
}