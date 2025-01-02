#include <vector> 
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    int findGCD(vector<int>& nums) {
        auto p = minmax_element(nums.begin(), nums.end());
        int min=*p.first;
        int max=*p.second;

        return __gcd(min,max);
    }
};
