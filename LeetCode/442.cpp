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
    vector<int> findDuplicates(vector<int>& nums) {

        unordered_set<int> hi;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (hi.find(nums[i]) != hi.end()) {
                ans.push_back(nums[i]);
                continue;
            }
            hi.insert(nums[i]);
        }
        return ans;
    }
};


class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++)
        {
            int x = abs(nums[i]);
            if (nums[x-1]<0)
            {
                ans.push_back(x);
            }
            nums[x-1]*=-1;
        }
        return ans;
    }
};