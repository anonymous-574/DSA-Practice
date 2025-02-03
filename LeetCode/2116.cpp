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

class Solution {
public:
    bool canBeValid(string s, string locked) {

        if (s.length() % 2 == 1) {
            return false;
        }

        stack<int> open, unlocked;

        int is_lock = 0;
        for (int i = 0; i < s.length(); i++) {

            if (locked[i] == '0') {
                unlocked.push(i);
            } else if (s[i] == '(') {
                open.push(i);
            } else if (s[i] == ')') {
                if (!open.empty()) {
                    open.pop();
                } else if (!unlocked.empty()) {
                    unlocked.pop();
                } else {
                    return false;
                }
            }
        }

        while (!open.empty() && !unlocked.empty() &&
               unlocked.top() > open.top()) {
            open.pop();
            unlocked.pop();
        }

        if (!open.empty()) {
            return false;
        }

        return true;
    }
};