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
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[0] == b[0])
                     return a[1] > b[1]; // Descending order for second element
                 return a[0] < b[0];     // Ascending order for first element
             });

        for (int i = 0; i < intervals.size(); i++) {
            if (ans.empty() || ((ans.back()[0] < intervals[i][0]) &&
                                ans.back()[1] < intervals[i][1])) {
                ans.push_back(intervals[i]);
            }
        }

        return ans.size();
    }
};