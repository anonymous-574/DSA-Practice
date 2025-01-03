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
    int waysToSplitArray(vector<int>& nums) {
        
        vector <long long> prefix(nums.size());
        prefix[0]=nums[0];
        for (int i = 1; i < nums.size(); i++){
            prefix[i]=nums[i]+prefix[i-1];
        }
        
        int ways=0;
        long long end = prefix[nums.size()-1];
        for (int i = 0; i < nums.size()-1; i++)
        {
            if (prefix[i]>=  (end-prefix[i]))
            {
                ways++;
            }
        }
        
    return ways;
    }
};

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();