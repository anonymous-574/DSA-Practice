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
    bool canConstruct(string s, int k) {

        if (s.length() < k) {
            return false;
        }

        int arr[26] = {0};

        for (int i = 0; i < s.length(); i++) {
            arr[s[i] - 'a']++;
        }

        int is_odd = 0;
        for (int i = 0; i < 26; i++) {
            if (arr[i] % 2 != 0) {
                is_odd++;
            }
        }

        if (is_odd > k) {
            return false;
        }
        return true;
    }
};