#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector <int> ans;

        for (int i = 0; i < nums.size(); i++)
        {
            ans.push_back(nums[nums[i]]);
        }
    return ans;
    }
};