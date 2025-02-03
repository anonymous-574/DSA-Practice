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
    int is_good(string a, string b) {
        if (a.length() > b.length()) {
            return 0;
        }

        for (int i = 0; i < a.length() && i < b.length(); i++) {
            if (a[i] != b[i]) {
                return 0;
            }
        }

        for (int i = a.length() - 1, j = b.length() - 1; i >= 0 && j >= 0;
             i--, j--) {
            if (a[i] != b[j]) {
                return 0;
            }
        }

        return 1;
    }

    int countPrefixSuffixPairs(vector<string>& words) {

        int ans = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                ans += is_good(words[i], words[j]);
            }
        }
        return ans;
    }
};