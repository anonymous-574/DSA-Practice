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
        int minOperations(vector<int>& nums) {
    
            int op = 0;
            for (int i = 0; i < nums.size() - 2; i++) {
                if (nums[i] == 0) {
                    nums[i] = nums[i] ^ 1; // toggling
                    nums[i + 1] = nums[i + 1] ^ 1;
                    nums[i + 2] = nums[i + 2] ^ 1;
                    op++;
                }
            }
    
            for (int i = nums.size() - 3; i < nums.size(); i++) {
                if (nums[i] == 0) {
                    return -1;
                }
            }
            return op;
        }
    };