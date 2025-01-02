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
    int smallestEqual(vector<int>& nums) {
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (i%10==nums[i])
            {
                return i;
            }
            
        }
        return -1;
    }
};