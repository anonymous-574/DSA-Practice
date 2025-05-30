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
        vector<vector<int>> mergeArrays(vector<vector<int>>& nums1,
                                        vector<vector<int>>& nums2) {
            vector<vector<int>> ans;
            int i = 0, j = 0;
            int n = nums1.size(), m = nums2.size();
    
            while (i < n && j < m) {
                if (nums1[i][0] == nums2[j][0]) {
                    ans.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
                    i++;
                    j++;
                } else if (nums1[i][0] < nums2[j][0]) {
                    ans.push_back({nums1[i][0], nums1[i][1]});
                    i++;
                } else {
                    ans.push_back({nums2[j][0], nums2[j][1]});
                    j++;
                }
            }
    
            while (i < n) {
                ans.push_back(nums1[i]);
                i++;
            }
    
            while (j < m) {
                ans.push_back(nums2[j]);
                j++;
            }
    
            return ans;
        }
    };