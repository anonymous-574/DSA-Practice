#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <limits>
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        vector<int> bef, aft;

        while (head != NULL) {
            if (head->val >= x) {
                aft.push_back(head->val);
            } else {
                bef.push_back(head->val);
            }
            head = head->next;
        }
        bef.insert(bef.end(), aft.begin(), aft.end());

        if (bef.size() == 0) {
            return NULL;
        }

        ListNode* ans = new ListNode(bef[0]);
        ListNode* curr = ans;
        for (int i = 1; i < bef.size(); i++) {
            curr->next = new ListNode(bef[i]);
            curr = curr->next;
        }

        return ans;
    }
};