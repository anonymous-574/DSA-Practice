#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            int ans = 0;
            unordered_set<int> temp;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] < k) {
                    return -1;
                } else if (temp.find(nums[i]) == temp.end() && nums[i] > k) {
                    ans++;
                    temp.insert(nums[i]);
                }
            }
            return ans;
        }
    };