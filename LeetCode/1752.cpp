#include <vector> 
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        if (nums == sorted) {
            return true;
        }

        vector<int> rot = sorted;
        for (int x = 0; x < nums.size(); x++) {
            for (int i = 0; i < nums.size(); i++) {
                rot[(i + x) % nums.size()] = sorted[i];
            }
            if (rot == nums) {
                return true;
            }
        }
        return false;
    }
};

//optimal
//basic reasoning
//in rotated array they can be only one violation of sorted rule
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        
        // Check if the array is non-decreasing
        for (int i = 1; i < n; i++)
            if (nums[i - 1] > nums[i])
                count++;
        
        // Check if the last element is greater than the first element
        if (nums[n - 1] > nums[0])
            count++;
        
        // If the count of violations is less than or equal to 1, return true
        return count <= 1;
    }
};