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
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> mp;
        for (int i : arr) {
            mp[i]++;
        }

        int ans = -1;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            if (it->first == it->second) {
                ans = max(ans, it->first);
            }
        }
        return ans;
    }
};