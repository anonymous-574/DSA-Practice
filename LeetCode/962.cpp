#include <vector>
#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {

    vector<pair<int,int>> p;
    vector <int> idx;

     for (int i=0; i<nums.size(); i++)
        p.push_back( make_pair(nums[i],i) );

    sort(p.begin(), p.end());

    for (int i=0 ; i<p.size(); i++)
    { 
        idx.push_back(p[i].second);
    }    

     int maxDiff = 0;
    int minElement = idx[0];
    int minIndex = 0;

    for (int i = 1; i < idx.size(); ++i) {
        // Update minElement and minIndex if we find a new minimum
        if (idx[i] < minElement) {
            minElement = idx[i];
            minIndex = i; // Update index of minimum element
        } else if (i > minIndex) {
            // Calculate the difference if the current index is greater than minIndex
            int diff = idx[i] - minElement;
            maxDiff = std::max(maxDiff, diff);
        }
    }

    return maxDiff;
    }
}; 