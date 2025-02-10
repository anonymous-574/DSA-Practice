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
        int maxDepth(string s) {
            int ans = 0, temp = 0;
            for (char c : s) {
                if (c == '(') {
                    temp++;
                    ans = max(ans, temp);
                } else if (c == ')') {
                    temp--;
                }
            }
            return ans;
        }
    };