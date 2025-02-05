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
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2) {
            return true;
        }

        char a, b, c, d;
        int temp = 0;
        int changes = 0;
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) {
                if (temp == 0) {
                    a = s1[i];
                    b = s2[i];
                    temp++;
                } else if (temp == 1) {
                    c = s1[i];
                    d = s2[i];
                }
                changes++;
            }
        }

        if (changes == 2 && (a == d && b == c)) {
            return true;
        }
        return false;
    }
};