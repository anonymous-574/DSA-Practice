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
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
            int n=citations.size();
            int idx=0;
            for (int i = 0; i < n; i++){
                if (n-i<=citations[i]){
                    return n-i;
                }
            }
            return 0;
              
    }
};