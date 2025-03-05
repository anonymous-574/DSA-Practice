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
        bool divideArray(vector<int>& nums) {
            unordered_map<int, int> mp;
    
            for (int i : nums) {
                mp[i]++;
            }
    
            for (auto i : mp) {
                if (i.second % 2 != 0) {
                    return false;
                }
            }
            return true;
        }
    };