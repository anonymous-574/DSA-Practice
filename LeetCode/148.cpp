#include <bits/stdc++.h>
#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

using namespace std;
using vi = vector<int>;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode* merge(ListNode * head1, ListNode* head2) {
            ListNode* ptr1 = head1;
            ListNode* ptr2 = head2;
            ListNode* head3 = new ListNode(0);  
            ListNode* temp3 = head3;
            while(ptr1 != NULL && ptr2 != NULL) {
                if(ptr1-> val <= ptr2-> val) {
                    temp3->next = ptr1;
                    ptr1 = ptr1->next;
                }
                else{
                    temp3->next = ptr2;
                    ptr2 = ptr2->next;
                }
                temp3 = temp3->next;
            }
            if(ptr1 != NULL) {
                temp3->next = ptr1;
            }
            if(ptr2 != NULL) {
                temp3->next = ptr2;
            }
            return head3->next;
        }
    
        ListNode* sortList(ListNode* head) {
            if (!head || !head->next) return head;  
            ListNode* slow = head;
            ListNode* fast = head;
            ListNode* prev = NULL;
            while (fast && fast->next) {
                prev = slow;
                slow = slow->next;
                fast = fast->next->next;
            }
            prev->next = NULL;  
            ListNode* l1 = sortList(head);
            ListNode* l2 = sortList(slow);
            return merge(l1, l2);
        }
    };