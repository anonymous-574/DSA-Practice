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

//VERY BAD
class Solution {
    public:
        vector<int> applyOperations(vector<int>& nums) {
            int cnt = 0;
            for (int i = 0; i < nums.size() - 1; i++) {
                if (nums[i] == nums[i + 1]) {
                    nums[i] *= 2;
                    nums[i + 1] = 0;
                }
    
                if (nums[i] == 0) {
                    cnt++;
                    nums.erase(find(nums.begin(), nums.end(), 0));
                    i--;
                }
            }
    
            for (int i = 0; i < cnt; i++) {
                nums.push_back(0);
            }
            return nums;
        }
    };


class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int zero = 0;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                zero++;
                continue;
            }
            if (i < nums.size() - 1 && nums[i] == nums[i + 1]) {
                ans.push_back(nums[i] * 2);
                zero++;
                i++;
            } else {
                ans.push_back(nums[i]);
            }
        }

        while (zero--) {
            ans.push_back(0);
        }

        return ans;
    }
};

//IN PLACE
class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        int writeIndex = 0;  // Pointer to place non-zero elements

        for (int index = 0; index < n; index++) {
            // Step 1: Merge adjacent equal elements if they are non-zero
            if (index < n - 1 && nums[index] == nums[index + 1] && nums[index] != 0) {
                nums[index] *= 2;
                nums[index + 1] = 0;
            }

            // Step 2: Shift non-zero elements to the front
            if (nums[index] != 0) {
                if (index != writeIndex) {
                    swap(nums[index], nums[writeIndex]);
                }
                writeIndex++;
            }
        }

        return nums;
    }
};