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

//actually faster
//n log n solution
class Solution {
    public:
        bool divideArray(vector<int>& nums) {
            // Sort array to group equal elements together
            sort(nums.begin(), nums.end());
    
            // Check consecutive pairs in sorted array
            for (int pos = 0; pos < nums.size(); pos += 2) {
                // If any pair doesn't match, we can't form n equal pairs
                if (nums[pos] != nums[pos + 1]) {
                    return false;
                }
            }
    
            // All pairs found successfully
            return true;
        }
    };