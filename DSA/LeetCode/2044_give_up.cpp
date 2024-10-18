#include <vector> 
#include <iostream>
#include <bits/stdc++.h>
#include <unordered_set> 
using namespace std;

class Solution {
public:

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> output;
        output.push_back({});
        for (int num : nums) {
            vector<vector<int>> newSubsets;
            for (vector<int> curr : output) {
                vector<int> temp = curr;
                temp.push_back(num);
                newSubsets.push_back(temp);
            }
            for (vector<int> curr : newSubsets) {
                output.push_back(curr);
            }
        }
        return output;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int ans=0;
        for (int i = 0; i < nums.size(); i++)
        {
            ans= ans | nums[i] ;
        }
        //ans is now what we must look to 

        vector<vector<int>> output= subsets(nums);

        int cnt=0;

        int temp=0;
        for (int i = 0; i < output.size(); i++)
        {
            temp=0;
            for (int j = 0; j < output[i].size(); j++)
            {
                temp=temp | output[i][j];
            }
            if(temp==ans)
            {
                cnt++;
            }
        }
        
        

    return cnt;
    }
};

class Solution
{
public:
    void backtrack(const vector<int> &nums, int index, int currentOR, int maxOR, int &count)
    {
        if (currentOR == maxOR)
        {
            count++;
        }

        for (int i = index; i < nums.size(); ++i)
        {
            backtrack(nums, i + 1, currentOR | nums[i], maxOR, count);
        }
    }

    int countMaxOrSubsets(vector<int> &nums)
    {
        int maxOR = 0;

        // Step 1: Compute the maximum OR
        for (int num : nums)
        {
            maxOR |= num;
        }

        int count = 0;
        // Step 2: Backtrack to count the subsets
        backtrack(nums, 0, 0, maxOR, count);

        return count;
    }
};
