#include <vector>
#include <iostream>
#include <bits/stdc++.h> 
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int s=nums.size();
        for (int i = 0; i < s; i++)
        {
            for (int j = i+1; j < s; j++)
            {
                if (nums[i]+nums[j]==target)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                    break;
                    break;
                }
                
            }
            
        }
        
    return ans;
    }
};