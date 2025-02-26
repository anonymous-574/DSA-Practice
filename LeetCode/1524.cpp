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
        int numOfSubarrays(vector<int>& arr) {
            int ans = 0, sum = 0;
            int even = 1, odd = 0;
    
            for (int i = 0; i < arr.size(); i++) {
                sum += arr[i];
                if (sum % 2 == 0) {
                    even++;
                    ans += odd;
                } else {
                    odd++;
                    ans += even;
                }
                ans %= 1000000007;
            }
            return ans;
        }
    };