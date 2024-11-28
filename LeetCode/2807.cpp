typedef struct ListNode
{
    int data;
    ListNode * next;
}ListNode;

#include <stdlib.h>

class Solution {
public:

    int gcd_calc (int a , int b)
    {
        int result =0;
        if (a>b)
        {
            result=b;
        }
        else
        {
            result=a;
        }
        
        
        while (result > 0) { 
            if (a % result == 0 && b % result == 0){ 
                break; 
            } 
        result--; 
        } 
        return result; 

    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        
        ListNode * temp1 = head;
        ListNode * temp2 = head->next;
        int gcd_to_insert=0;

        while (temp1->next!=NULL)
        {
            gcd_to_insert=gcd_calc(temp1->data , temp2->data);
            ListNode * new_node = (ListNode *) malloc(sizeof(ListNode));
            new_node->data=gcd_to_insert;
            temp1->next = new_node;
            new_node->next=temp2;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return head;
    }
};