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
    static bool customComparator(int a, int b) {
        string strA = to_string(a);
        string strB = to_string(b);
        return (strA + strB) > (strB + strA);
    }

    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), customComparator);
        string ans = "";
        for (int num : nums) {
            ans += to_string(num);
        }

        if (ans[0] == '0') {
            return "0";
        }
        return ans;
    }
};