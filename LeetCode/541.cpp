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
    string reverseStr(string s, int k) {
        string temp = "", ans = "";
        bool to_rev = true;
        int te = 0;
        for (int i = 0; i < s.length(); i++) {
            temp += s[i];
            te++;
            if (te == k) {
                if (to_rev) {
                    reverse(temp.begin(), temp.end());
                }
                ans += temp;
                temp = "";
                te = 0;
                // flip it
                to_rev ^= true;
            }
        }
        if (to_rev) {
            reverse(temp.begin(), temp.end());
        }
        ans += temp;
        return ans;
    }
};