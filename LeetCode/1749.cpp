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
        int maxAbsoluteSum(vector<int>& nums) {
            int min_sum = 0, max_sum = 0;
            int sum = 0;
            for (int i = 0; i < nums.size(); i++) {
                sum += nums[i];
                min_sum = min(sum, min_sum);
                max_sum = max(sum, max_sum);
            }
    
            return max_sum - min_sum;
        }
    };