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
    int balancedStringSplit(string s) {
        int temp = 0, ans = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'L') {
                temp++;
            } else {
                temp--;
            }
            if (temp == 0) {
                ans++;
            }
        }
        return ans;
    }
};