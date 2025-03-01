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
        int lenLongestFibSubseq(vector<int>& arr) {
            unordered_set<int> temp(arr.begin(), arr.end());
            int ans = 0;
            int t = 2, x, y, t_y;
            for (int i = 0; i < arr.size(); i++) {
                for (int j = i + 1; j < arr.size(); j++) {
                    x = arr[j];
                    y = arr[i] + arr[j];
                    while (temp.find(y) != temp.end()) {
                        t++;
                        t_y = y;
                        y = y + x;
                        x = t_y;
                    }
                    ans = max(t, ans);
                    t = 2;
                }
            }
            return ans == 2 ? 0 : ans;
        }
    };