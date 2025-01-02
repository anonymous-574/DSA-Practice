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
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int min_diff=INT_MAX;

        for (int i = 0; i < arr.size()-1; i++)
        {
            min_diff=min(min_diff,abs(arr[i+1]-arr[i]));
        }
        cout<<min_diff;
        vector<vector<int>> ans;
        vector<int> temp;
        for (int i = 0; i < arr.size()-1; i++)
        {
            if (abs(arr[i+1]-arr[i])==min_diff)
            {
                temp.push_back(arr[i]);
                temp.push_back(arr[i+1]);
                ans.push_back(temp);
                temp.clear();
            }
        }
    return ans;
    }
};