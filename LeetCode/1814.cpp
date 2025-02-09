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
        int rev(int num) {
            int rev_num = 0;
            while (num > 0) {
                rev_num = rev_num * 10 + num % 10;
                num = num / 10;
            }
            return rev_num;
        }
    
        int countNicePairs(vector<int>& nums) {
            unordered_map<int, int> freq;
            int ans = 0;
            for (int i = 0; i < nums.size(); i++) {
                int key = nums[i] - rev(nums[i]);
                ans = (ans + freq[key]) % 1000000007;
                freq[key]++;
            }
            return ans;
        }
    };