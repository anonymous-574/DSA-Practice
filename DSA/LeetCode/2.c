#include <stdio.h>
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

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
    
    struct ListNode* temp1=l1;
    struct ListNode* temp2=l2;
    int tempsum=0;

    if (s1>s2)
    {
        //add s2 to s1 and return reversed s1
        while (temp1->next!=NULL && temp2->next!=NULL)
        {
            tempsum=temp2->val+temp1->val;

            if (tempsum>9)
            {
                tempsum%=10;
                if (temp2->next==NULL)
                {
                    //allocate?
                    struct ListNode * node =(struct ListNode * )malloc(sizeof(struct ListNode ));
                    node->next=NULL;
                    temp2->next=node;
                    node->val=0; 
                }
                
                temp2->next->val+=1;
                temp2->val=tempsum;
            }
            else
            {
                temp2->val+=temp1->val;
            }
            
            temp1=temp1->next;
            temp2=temp2->next;
        }
        temp2->val+=temp1->val;
        return l1;
    }
    else if (s2>s1)
    {
        //add s1 to s2 and return reversed s2
        while (temp1->next!=NULL && temp2->next!=NULL)
        {

            tempsum=temp2->val+temp1->val;

            if (tempsum>9)
            {
                tempsum%=10;
                if (temp1->next==NULL)
                {
                    //allocate?
                    struct ListNode * node =(struct ListNode * )malloc(sizeof(struct ListNode ));
                    node->next=NULL;
                    temp1->next=node;
                    node->val=0; 
                }
                
                temp1->next->val+=1;
                temp1->val=tempsum;
            }
            else
            {
                temp1->val+=temp2->val;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        temp1->val+=temp2->val;
        return l2;
    }
    else
    {
        //equal size
        //add any
        while (temp1->next!=NULL && temp2->next!=NULL)
        {
            tempsum=temp2->val+temp1->val;

            if (tempsum>9)
            {
                tempsum%=10;
                if (temp1->next==NULL)
                {
                    //allocate?
                    struct ListNode * node =(struct ListNode * )malloc(sizeof(struct ListNode ));
                    node->next=NULL;
                    temp1->next=node;
                    node->val=0; 
                }
                
                temp1->next->val+=1;
                temp1->val=tempsum;
            }
            else
            {
                temp1->val+=temp2->val;
            }

            temp1=temp1->next;
            temp2=temp2->next;
        }
        temp1->val+=temp2->val;
        return l1;
    }
    //fallback
    return NULL;
}