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
        int dig(int i) {
            int digitSum = 0;
            while (i > 0) {
                digitSum += i % 10;
                i /= 10;
            }
            return digitSum;
        }
    
        int maximumSum(vector<int>& nums) {
            vector<priority_queue<int>> dig_sum(81);
            for (int i : nums) {
                dig_sum[dig(i) - 1].push(i);
            }
            int temp = -1, ans = -1;
            for (int i = 0; i < dig_sum.size(); i++) {
                if (dig_sum[i].size() >= 2) {
                    temp = dig_sum[i].top();
                    dig_sum[i].pop();
                    temp += dig_sum[i].top();
                }
                ans = max(temp, ans);
                temp = -1;
            }
            return ans;
        }
    };