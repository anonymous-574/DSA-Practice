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
    int removeDuplicates(vector<int>& nums) {

        int counter = 1;
        int curr = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (curr == nums[i]) {
                counter++;
                if (counter == 3) {
                    nums.erase(nums.begin() + i);
                    counter--;
                    i--;
                }
            } else {
                curr = nums[i];
                counter = 1;
            }
        }
        return nums.size();
    }
};