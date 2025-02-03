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
    int minimumLength(string s) {

        vector<int> cnt(26, 0);

        for (int i = 0; i < s.length(); i++) {
            cnt[s[i] - 'a']++;
        }

        int ans = 0;

        for (int i = 0; i < cnt.size(); i++) {
            if (cnt[i] ==0) {
                continue;
            } else if (cnt[i] % 2 == 0) {
                ans += 2;
            } else {
                ans++;
            }
        }

        return ans;
    }
};