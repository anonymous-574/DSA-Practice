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
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans=INT_MAX;
        //k is window size
        for (int i = 0; i < nums.size()-k+1; i++)
        {
            //end-start for the window
            ans=min(ans,nums[k-1+i]-nums[i]);
        }
    return ans;
    }
};