#include <stdio.h>
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

/*
// i give up 
int size_of_ll(struct ListNode* l)
{
    int size=0;
    struct ListNode* temp=l;
    while (temp->next!=NULL)
    {
        size++;
        temp=temp->next;
    }
    return size;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int s1=size_of_ll(l1);
    int s2=size_of_ll(l2);
    
    struct ListNode* temp=l1;
    int tempsum=0;

    if (s1<s2)
    {
        l1=l2;
        l2=temp;
    }

    //guaranteed that l1 >l2 or l1=l2
    struct ListNode* temp1=l1;
    struct ListNode* temp2=l2;
    int c=0;
    while (temp2->next!=NULL)
        {
            tempsum=temp2->val+temp1->val+c;
            if (tempsum >9)
            {
                c=1;
            }
            temp1->val=tempsum%10;
            //c= (temp2->val+temp1->val+c)/10;
            if (temp1->next==NULL)
            {
                struct ListNode * node =(struct ListNode * )malloc(sizeof(struct ListNode ));
                node->next=NULL;
                temp1->next=node;
                node->val=0; 
            }

            temp1->next->val+=c;
            temp1=temp1->next;
            temp2=temp2->next;
            c=0;
        }
        tempsum=temp2->val+temp1->val+c;
        temp1->val=tempsum%10;

        if (tempsum >9)
        {
            c=1;
        }

        while (temp1->next!=NULL)
        {
            tempsum=temp1->val+c;
            if (tempsum >9)
            {
                c=1;
            }
            temp1->val=tempsum%10;
            //c=(temp1->val+c)/10;

            if (temp1->next==NULL)
            {
                struct ListNode * node =(struct ListNode * )malloc(sizeof(struct ListNode ));
                node->next=NULL;
                temp1->next=node;
                node->val=0; 
            }
            temp1->next->val+=c; 
            temp1=temp1->next;
            c=0;
        }
        tempsum=temp1->val+c;
        temp1->val=tempsum%10;  

        return l1;
}
*/

/**
 * Definition for singly-linked list. 
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int size_of_ll(struct ListNode* l)
{
    int size=0;
    struct ListNode* temp=l;
    while (temp!=NULL)
    {
        size++;
        temp=temp->next;
    }
    return size;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int s1=size_of_ll(l1);
    int s2=size_of_ll(l2);
    struct ListNode* temp=l1;
    int tempsum=0;
    if (s1<s2)
    {
        l1=l2;
        l2=temp;
    }

    //guaranteed that l1 >l2 or l1=l2
    struct ListNode* temp1=l1;
    struct ListNode* temp2=l2;
    struct ListNode* prev=temp1;
    int c=0;
    while (temp2!=NULL)
    {
        tempsum=(temp2->val+temp1->val+c)%10;
        c=(temp2->val+temp1->val+c)/10;
        printf(" sum:%d\n",tempsum);
        printf(" c:%d\n",c);
        temp1->val=tempsum;
        prev=temp1;
        temp1=temp1->next;
        temp2=temp2->next;
    }
    while (temp1!=NULL)
    {
        tempsum=(temp1->val+c)%10;
        c=(temp1->val+c)/10;
        temp1->val=tempsum;
        prev=temp1;
        temp1=temp1->next;
    }
    if(c!=0)
    {
        struct ListNode* node=(struct ListNode*)malloc(sizeof(struct ListNode));
        node->val = c;
        node->next = NULL;
        prev->next = node;
    }   
    return l1;
}
