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
        vector<long long> sumOfThree(long long num) {
            long long x = num / 3;
            if (x * 3 == num) {
                return {x - 1, x, x + 1};
            }
            return {};
        }
    };