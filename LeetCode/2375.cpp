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

/*
    Pad the pattern with an artificial "I" at the front
    Count how many "D" directly follow each "I"
    when you encounter "I", place the smallest available element plus the offset determined above
    when you encounter "D", place the element one less than the previous value
*/

class Solution {
    public:
        string smallestNumber(string pattern) {
            string ans="";
            stack<int>st;

            for (int i=0; i<=pattern.length();i++){
                st.push(i+1);

                if (i==pattern.length() || pattern[i]=='I'){
                    while (!st.empty()){
                        ans+=to_string(st.top());
                        st.pop();
                    }
                }
            }

        return ans;
        }
    };

