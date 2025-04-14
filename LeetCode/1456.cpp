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
        int maxVowels(string s, int k) {
            int start = 0;
            int temp = 0, ans = 0;
            unordered_set<char> hi = {'a', 'e', 'i', 'o', 'u'};
            for (int i = 0; i < k; i++) {
                if (hi.find(s[i]) != hi.end()) {
                    temp++;
                }
            }
            ans = max(temp, ans);
            for (int i = k; i < s.length(); i++) {
                if (hi.find(s[start]) != hi.end()) {
                    temp--;
                }
                start++;
                if (hi.find(s[i]) != hi.end()) {
                    temp++;
                }
                ans = max(temp, ans);
            }
    
            return ans;
        }
    };