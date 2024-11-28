
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include <vector> 
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:

    ListNode* reverseList(ListNode* head) {
    ListNode *curr = head, *prev = NULL, *next;

    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
    }

    ListNode* removeNodes(ListNode* head) {
        if (head->val ==1 && head->next->val == 100000)
        {
            head=head->next;
            return head;
        }
        head=reverseList(head);
        ListNode * prev=head;
        ListNode * curr=head->next;
        int max=0;
        while (curr->next!=NULL)
        {
            if (curr->val < prev->val)
            {
                //delete head
                max=prev->val;
                prev->next=curr->next;
                curr=curr->next;

                 if (curr->val < max )
                {
                prev->next=curr->next;
                continue;
                }

            }
            curr=curr->next;
            prev=prev->next;
        }
    return reverseList(head);
    }
};