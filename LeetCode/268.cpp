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
    int missingNumber(vector<int>& nums) {

        unordered_set<int> hold;
        for (int i = 0; i < nums.size(); i++) {
            hold.insert(nums[i]);
        }

        for (int i = 0; i <= nums.size(); i++) {
            if (hold.find(i) == hold.end()) {
                return i;
            }
        }

        return -1;
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int Tsum = (n*(n+1))/2;
        return  Tsum - accumulate(nums.begin(),nums.end(),0);
    }
};