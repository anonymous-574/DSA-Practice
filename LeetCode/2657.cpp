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
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> ans;
        unordered_set<int> a1;
        unordered_set<int> b1;
        int tempsum = 0;
        for (int i = 0; i < A.size(); i++) {
            a1.insert(A[i]);
            b1.insert(B[i]);
            if (A[i] == B[i]) {
                tempsum++;
                ans.push_back(tempsum);
                continue;
            }
            if (a1.find(B[i]) != a1.end()) {
                tempsum++;
            }
            if (b1.find(A[i]) != b1.end()) {
                tempsum++;
            }
            ans.push_back(tempsum);
        }

        return ans;
    }
};