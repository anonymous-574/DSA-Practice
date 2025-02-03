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
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>n1(nums1.begin(),nums1.end());
        unordered_set<int> hold;
        for (int i :nums2){
            if (n1.find(i)!=n1.end()){
                hold.insert(i);
            }
        }
        vector<int>ans(hold.begin(),hold.end());
    return ans;
    }
};