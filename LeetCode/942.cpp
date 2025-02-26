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
        vector<int> diStringMatch(string s) {
            vector<int> ans;
            stack<int> st;
    
            for (int i = 0; i <= s.length(); i++) {
                st.push(i);
    
                if (i == s.length() || s[i] == 'I') {
                    while (!st.empty()) {
                        ans.push_back(st.top());
                        st.pop();
                    }
                }
            }
    
            return ans;
        }
    };