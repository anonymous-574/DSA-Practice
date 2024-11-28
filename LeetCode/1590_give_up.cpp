#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int size = nums.size();

        int total=0;
        //find the sum of nums %p
        for (int i = 0; i < size; i++)
        {
            total = (total+nums[i]) %p;
        }
        
        int target = total%p;
        if (target==0)
        {
            return 0;
        }

        unordered_map <int,int> map1;
        map1[0]=-1;
        int curr_sum=0, minLen=size;

        for (int i = 0; i < size; i++)
        {
            curr_sum = (curr_sum + nums[i])%p;
            int needed = (curr_sum-target+p)%p;

            if (map1.find(needed)!=map1.end())
            {
                minLen=min(minLen , i-map1[needed]);
            }
            
            map1[curr_sum]=i;
        }
        
        if (minLen==size)
        {
            return -1;
        }
        else
        {
            return minLen;
        }
        
        
    }
};