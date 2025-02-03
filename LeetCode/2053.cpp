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
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> temp;

        for (int i = 0; i < arr.size(); i++) {
            temp[arr[i]]++;
        }

        for (string& str : arr) {
            if (temp[str] == 1) {
                k--;
            }
            if (k == 0) {
                return str;
            }
        }
        return "";
    }
};