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
        int minOperations(vector<int>& nums, int k) {
            priority_queue<long long, vector<long long>, greater<long long>> q(nums.begin(),
                                                             nums.end());
    
            long long x, y, ans = 0;
            while (q.size() >= 2 && q.top() < k) {
                x = q.top();
                q.pop();
                y = q.top();
                q.pop();
                //q.push((min(x, y) * 2) + max(x, y));
                //because min heap ppt
                q.push((x * 2) +  y);
                ans++;
            }
            return ans;
        }
    };