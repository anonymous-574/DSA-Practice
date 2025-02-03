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
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());

        for (int i = 0; i < intervals.size() - 1;) {
            if (intervals[i][1] >= intervals[i + 1][0]) {
                cout << intervals[i][1] << " " << intervals[i + 1][0] << endl;

                if (intervals[i][1] > intervals[i + 1][1]) {
                    intervals.erase(intervals.begin() + i + 1);
                    continue;
                }
                intervals[i][1] = intervals[i + 1][1];
                intervals.erase(intervals.begin() + i + 1);
            } else {
                i++;
            }
        }

        return intervals;
    }
};

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        
        for (int i = 0; i < intervals.size(); i++) {
            if (ans.empty() || ans.back()[1] < intervals[i][0]) {
                ans.push_back(intervals[i]);
            } else {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }

        return ans;
    }
};