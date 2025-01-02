#include <vector> 
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue <pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>> > pq;

        for (int i = 0; i < nums.size(); i++)
        {
            pq.push(make_pair(nums[i],i));
        }
        
        int num,idx;
        for (int i = 0; i < k; i++)
        {
            num=pq.top().first;
            idx=pq.top().second;
            pq.pop();
            num*=multiplier;
            nums[idx]=num;
            pq.push(make_pair(num,idx));
        }
    return nums;
    }
};


//faster
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
    
    for (int i = 0; i < k; i++)
    {
        int idx = min_element(nums.begin(),nums.end())-nums.begin();
        nums[idx]*=multiplier;
    }

    return nums;
    }
};