#include <vector>
#include <iostream>
#include <bits/stdc++.h> 
#include <math.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int result= pow(2,maximumBit)-1;
        cout<<result;
        vector <int> ans;

        int temp_res=nums[0]^result;
        ans.push_back(temp_res);
        for (int i = 1; i <nums.size(); i++)
        {
            temp_res=temp_res^nums[i];
            ans.push_back(temp_res);
        }
    reverse(ans.begin(),ans.end());
    return ans;
    }
};