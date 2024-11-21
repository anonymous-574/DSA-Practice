#include <stdio.h>
#include <stdlib.h>

struct ListNode { 
    int val;
    struct ListNode *next;
};

struct ListNode* swapPairs(struct ListNode* head) {

    if (head==NULL || head->next==NULL)
    {
        return head;
    }
    
    struct ListNode* curr=head; 
    struct ListNode* dum = (struct ListNode*) malloc(sizeof(struct ListNode));
    struct ListNode* prev=dum;
    
    while (curr!=NULL && curr->next!=NULL)
    {
        prev->next=curr->next;
        curr->next=prev->next->next;
        prev->next->next=curr;

        prev=curr;
        curr=curr->next;
    }
    return dum->next;
}