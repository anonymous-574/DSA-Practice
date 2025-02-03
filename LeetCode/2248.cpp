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
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int> ans;
        vector<unordered_set<int>>hi(nums.size());
        for (int i = 0; i < nums.size(); i++){
            for (int j = 0; j < nums[i].size(); j++){
                hi[i].insert(nums[i][j]);
            }
        }
        
        int temp=0;
        for (int i = 0; i < nums[0].size(); i++){
            for (int j = 1; j < nums.size(); j++){
                if (hi[j].find(nums[0][i])!=hi[j].end()){
                    temp++;
                }
            }

            if (temp==nums.size()-1){
                ans.push_back(nums[0][i]);
            }
            temp=0;
        }
        sort(ans.begin(),ans.end());
    return ans;
    }
};