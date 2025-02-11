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
        bool check_match(stack<char> st, string part, int part_len) {
            stack<char> temp = st;
            int i = 0;
    
            while (i != part_len) {
                if (part[part_len - i - 1] != temp.top()) {
                    return false;
                }
                temp.pop();
                i++;
            }
            return true;
        }
        string removeOccurrences(string s, string part) {
            int s_size = s.size(), p_size = part.size();
            stack<char> st;
    
            for (int i = 0; i < s_size; i++) {
                st.push(s[i]);
                if (st.size() >= p_size) {
                    // check match
                    if (check_match(st, part, p_size)) {
                        for (int k = 0; k < p_size; k++) {
                            st.pop();
                        }
                    }
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