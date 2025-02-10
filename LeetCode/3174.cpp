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
        string clearDigits(string s) {
            stack<char> st;
            unordered_set<char> chk = {'1', '2', '3', '4', '5',
                                       '6', '7', '8', '9', '0'};
            for (char i : s) {
                if (chk.find(i) == chk.end()) {
                    st.push(i);
                } else {
                    st.pop();
                }
            }
            string ans = "";
            while (!st.empty()) {
                ans += st.top();
                st.pop();
            }
            reverse(ans.begin(), ans.end());
    
            return ans;
        }
    };

class Solution {
    public:
        string clearDigits(string s) {
            string ans;
    
            for (char c : s) {
                if (isdigit(c)) {
                    if (!ans.empty()) {
                        ans.pop_back();
                    }
                } else {
                    ans.push_back(c);
                }
            }
            return ans;
        }
    };