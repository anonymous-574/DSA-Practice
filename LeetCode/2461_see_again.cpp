#include <deque>
#include <iostream>
#include <algorithm>
#include <unordered_set> 
#include <queue>
#include <bits/stdc++.h>
using namespace std;

/*
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> s;
        long long ans=0;
        long long curr=0;

        for (int i = 0; i < k; i++)
        {
            if (s.find(nums[i])==s.end())
            {
                //not found
                s.insert(nums[i]);
                curr+=nums[i];
                
            }
            else
            {
              // go ahead till there is no match
            }
        }

        ans=max(ans,curr);
        
        for (int i = 0; i < nums.size()-k; i++)
        {
            s.insert(nums[i]);
            curr-=nums[i];
            curr+=nums[i+k];
        }
    return ans;
    }
};
*/

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0;
        long long currentSum = 0;
        int begin = 0;
        int end = 0;

        unordered_map<int, int> numToIndex;

        while (end < nums.size()) {
            int currNum = nums[end];
            int lastOccurrence =
                (numToIndex.count(currNum) ? numToIndex[currNum] : -1);

            // if current window already has number or if window is too big,
            // adjust window
            while (begin <= lastOccurrence || end - begin + 1 > k) {
                currentSum -= nums[begin];
                begin++;
            }
            numToIndex[currNum] = end;
            currentSum += nums[end];
            if (end - begin + 1 == k) {
                ans = max(ans, currentSum);
            }
            end++;
        }
        return ans;
    }
};