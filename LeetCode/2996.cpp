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
    int missingInteger(vector<int>& nums) {
        int sum =nums[0];
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i + 1] == nums[i] + 1) {
                sum+=nums[i + 1];
            } else {
                break;
            }
        }
        unordered_set<int> hold(nums.begin(), nums.end());
        while (true) {
            if (hold.find(sum) == hold.end()) {
                return sum;
            }
            sum++;
        }

        return -1;
    }
};