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
    int maxOperations(vector<int>& nums) {
        int score = nums[0] + nums[1];
        int ops = 1;

        for (int i = 2; i < nums.size() - 1; i += 2) {
            if (nums[i] + nums[i + 1] == score) {
                ops++;
            } else {
                break;
            }
        }

        return ops;
    }
};