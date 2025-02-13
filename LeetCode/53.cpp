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
        int maxSubArray(vector<int>& nums) {
            int max_sum = 0, temp = 0;
            int cnt = 0;
            for (int i = 0; i < nums.size(); i++) {
                temp += nums[i];
                if (nums[i] < 0) {
                    cnt++;
                }
                if (temp >= 0) {
                    max_sum = max(max_sum, temp);
                } else {
                    temp = 0;
                }
            }
            if (cnt == nums.size()) {
                return *max_element(nums.begin(), nums.end());
                ;
            }
            return max_sum;
        }
    };


//optimise ++
class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int curMax = 0, maxTillNow = INT_MIN;
            for(int c : nums)
                curMax = max(c, curMax + c),
                maxTillNow = max(maxTillNow, curMax);
            return maxTillNow;
        }
    };