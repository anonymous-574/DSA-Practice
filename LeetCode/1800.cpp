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
    int maxAscendingSum(vector<int>& nums) {
        int temp = nums[0], ans = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            ans = max(ans, temp);
            if (nums[i + 1] > nums[i]) {
                temp += nums[i + 1];
            } else {
                temp = nums[i + 1];
            }
        }
        ans = max(ans, temp);
        return ans;
    }
};