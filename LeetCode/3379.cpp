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
    vector<int> constructTransformedArray(vector<int>& nums) {
    int n=nums.size();
    vector<int>res(n,0);
    
    for (int i = 0; i < n; i++){
        res[i] = nums[(i + nums[i] % n + n) % n];
    }
    return res;      
    }
};