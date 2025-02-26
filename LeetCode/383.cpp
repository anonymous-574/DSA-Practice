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
        bool canConstruct(string ransomNote, string magazine) {
            vector<int> r1(26, 0), m1(26, 0);
            for (char i : ransomNote) {
                r1[i - 'a']++;
            }
            for (char i : magazine) {
                m1[i - 'a']++;
            }
    
            for (int i = 0; i < 26; i++) {
                if (r1[i] != 0) {
                    if (r1[i] > m1[i]) {
                        return false;
                    }
                }
            }
            return true;
        }
    };