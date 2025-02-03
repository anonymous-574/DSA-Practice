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
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> hold(nums.begin(),nums.end());

        int ans=INT_MIN, temp=1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (hold.find(nums[i]-1)==hold.end())
            {
                //we got the start
                while (true)
                {
                    if (hold.find(nums[i]+1)!=hold.end())
                    {
                        temp++;
                    }
                    else
                    {
                        break;
                    }
                    
                    
                    
                }
                ans=max(temp,ans);
            }
            
        }
        
    return ans;
    }
};