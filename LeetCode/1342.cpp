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
        int numberOfSteps(int num) {
            int ans = 0;
            while (num > 0) {
                if (num % 2 == 0) {
                    num /= 2;
                    ans++;
                } else {
                    num--;
                    ans++;
                }
            }
            return ans;
        }
    };
