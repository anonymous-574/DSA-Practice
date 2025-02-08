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
        int maximumWealth(vector<vector<int>>& accounts) {
            int ans = 0, temp = 0;
            for (int i = 0; i < accounts.size(); i++) {
                for (int j = 0; j < accounts[i].size(); j++) {
                    temp += accounts[i][j];
                }
                ans = max(ans, temp);
                temp = 0;
            }
            return ans;
        }
    };