#include <vector> 
#include <iostream>
#include <bits/stdc++.h>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/*
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode * fast=head;
        ListNode * slow=head;
        ListNode * chk = head;

        if(chk->next==NULL)
        {
            //1 node
            return NULL;
        }
        else if (chk->next->next==NULL)
        {
            head->next=NULL;
            return head;
        }

        while ( fast->next!=NULL && fast->next->next!=NULL )
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        if(fast->next!=NULL)
        {
            slow=slow->next;
        }

        slow->val=slow->next->val;
        slow->next = slow->next->next;
    return head;
    }
};

*/

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        

        if(head->next==NULL)
        {
            //1 node
            return NULL;
        }

        ListNode * fast=head->next->next;
        ListNode * slow=head;

        while ( fast!=NULL && fast->next!=NULL )
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next = slow->next->next;
    return head;
    }
};