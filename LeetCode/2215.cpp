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
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> n1(nums1.begin(), nums1.end()),
            n2(nums2.begin(), nums2.end());
        vector<vector<int>> ans;

        unordered_set<int> ans1, ans2;
        //if ans 1 was a vector it would have duplicates
        //since its an unordered set , we need not worry abt that
        for (int i : nums1) {
            if (n2.find(i) == n2.end()) {
                ans1.insert(i);
            }
        }

        for (int i : nums2) {
            if (n1.find(i) == n1.end()) {
                ans2.insert(i);
            }
        }

        vector<int> temp(ans1.begin(), ans1.end());
        ans.push_back(temp);
        vector<int> temp2(ans2.begin(), ans2.end());
        ans.push_back(temp2);

        return ans;
    }
};