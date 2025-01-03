#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        vector<int> prefix(nums.size());
        prefix[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            prefix[i] = nums[i] + prefix[i - 1];
        }

        int end = prefix[nums.size() - 1];
        if (end - nums[0] == 0) {
            return 0;
        }

        for (int i = 1; i < nums.size(); i++) {
            if (prefix[i - 1] == end - prefix[i - 1] - nums[i]) {
                return i;
            }
        }

        return -1;
    }
};