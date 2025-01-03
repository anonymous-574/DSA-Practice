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
    int minElement(vector<int>& nums) {
    
    int sum=0;
    int ans=INT_MAX;
    for (int i=0 ; i<nums.size();i++)
    {
        int x = nums[i];
        while (x > 0) {
            sum+=x%10;
            x = x / 10;
        }
        ans=min(ans,sum);
        sum=0;
    }
    return ans;
    }
};