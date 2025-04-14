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
        int minimumRecolors(string blocks, int k) {
            int start = 0;
            int temp = 0, ans = INT_MAX;
    
            for (int i = 0; i < k; i++) {
                if (blocks[i] == 'W') {
                    temp++;
                }
            }
            ans = min(temp, ans);
            for (int i = k; i < blocks.length(); i++) {
                if (blocks[start] == 'W') {
                    temp--;
                }
                start++;
                if (blocks[i] == 'W') {
                    temp++;
                }
                ans = min(temp, ans);
            }
    
            return ans;
        }
    };