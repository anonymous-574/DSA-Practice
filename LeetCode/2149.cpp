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
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos, neg;

        for (int i : nums) {
            if (i > 0) {
                pos.push_back(i);
            } else {
                neg.push_back(i);
            }
        }

        int t1 = 0, t2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                nums[i] = pos[t1];
                t1++;
            } else {
                nums[i] = neg[t2];
                t2++;
            }
        }

        return nums;
    }
};