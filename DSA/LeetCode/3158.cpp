#include <vector>
#include <iostream>
#include <bits/stdc++.h> 
#include <unordered_set>
using namespace std;

class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_set <int> all_nos;
        vector <int> dupli;
        all_nos.insert(-5);
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (all_nos.find(nums[i])==all_nos.end())
            {
                all_nos.insert(nums[i]);
            }
            else
            {
                dupli.push_back(nums[i]);
            } 
        }

        if(dupli.empty())
        {
            return 0;
        }
        int ans=dupli[0];
        for (int i = 1; i < dupli.size(); i++)
        {
            ans=ans^dupli[i];
        }
        
    return ans;
    }
};