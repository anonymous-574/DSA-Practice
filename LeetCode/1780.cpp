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
        string convertToTernary(int N) {
            if (N == 0)
                return "0"; 
            string ans = "";
            bool isNegative = (N < 0);
            while (N != 0) {
                int remainder = N % 3;
                N /= 3;
                if (remainder < 0) {
                    remainder += 3;
                    N += 1;
                }
                ans = char('0' + remainder) + ans;
            }
            return ans;
        }
    
        bool checkPowersOfThree(int n) {
            string ans = convertToTernary(n);
            for (char i : ans) {
                if (i == '2') {
                    return false;
                }
            }
            return true;
        }
    };