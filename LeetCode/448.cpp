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
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> temp;
        for (int i = 1; i <= nums.size(); i++) {
            temp[i] = 0;
        }

        for (int i = 0; i < nums.size(); i++) {
            temp[nums[i]] = 1;
        }

        for (int i = 1; i <= nums.size(); i++) {
            if (temp[i] == 0) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};

//good
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        //s by default has no duplicates
        unordered_set<int> s(nums.begin(),nums.end());
        vector<int> ans(nums.size()-s.size());
        for (int i = 1 , j=0; i <= nums.size(); i++)
            if (!s.count(i)) ans[j++]=i;
        return ans;
    }
};