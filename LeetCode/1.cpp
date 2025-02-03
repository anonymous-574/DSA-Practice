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


//O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>temp;

        for (int i = 0; i < nums.size(); i++){
            temp[nums[i]]=i;
        }
        
        int comp;
        for (int i = 0; i < nums.size(); i++){
            comp=target-nums[i];
            //second if to make sure that the same number isnt picked up again
            if(temp.count(comp) && temp[comp]!=i){
                return {i, temp[comp]};
            }
            
        }
    return {};
    }
};