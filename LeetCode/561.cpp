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
    int arrayPairSum(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        int ans=0;

        for (int i = 0; i < nums.size(); i+=2)
        {
            ans+=nums[i];
        }
        
        return ans;
    }
};