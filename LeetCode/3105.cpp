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
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc = 1, dec = 1;
        int temp1 = 1, temp2 = 1;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] < nums[i + 1]) {
                temp1++;
                temp2 = 1;
            } else if (nums[i] > nums[i + 1]) {
                temp1 = 1;
                temp2++;
            } else {
                temp1 = 1;
                temp2 = 1;
            }
            inc = max(inc, temp1);
            dec = max(dec, temp2);
        }
        return max(inc, dec);
    }
};

//Optimal
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int max_len = 1;
        int inc = 1, dec = 1;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] < nums[i + 1]) {
                inc++;
                dec = 1;
            } else if (nums[i] > nums[i + 1]) {
                inc = 1;
                dec++;
            } else {
                inc = 1;
                dec = 1;
            }
            max_len = max(max_len, max(inc, dec));
        }
        return max_len;
    }
};