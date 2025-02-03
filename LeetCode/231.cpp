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
    bool isPowerOfTwo(int n) {

        if (n == 1) {
            return true;
        }

        long long temp = 2;

        while (temp <= n) {
            if (temp == n) {
                return true;
            }
            temp = temp * 2;
        }
        return false;
    }
};

//number divisible by 2 must have only one '1' in binary
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)return false;
        int cnt = __builtin_popcount(n);
        return  (cnt==1) ? true:false;
    }
};