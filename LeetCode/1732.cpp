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
    int largestAltitude(vector<int>& gain) {
        int max_ht=0;
        int curr=0;

        for (int i = 0; i < gain.size(); i++)
        {
            curr+=gain[i];
            max_ht=max(max_ht,curr);
        }

    return max_ht;
    }
};