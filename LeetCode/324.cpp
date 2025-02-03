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
    void wiggleSort(vector<int>& nums) {
        vector<int> sorted(nums);
        int n = nums.size(), m = (n + 1) >> 1;
        sort(sorted.begin(), sorted.end());

        for (int i = m - 1, j = 0; i >= 0; i--, j += 2) nums[j] = sorted[i];
        for (int i = n - 1, j = 1; i >= m; i--, j += 2) nums[j] = sorted[i];
    }
};

