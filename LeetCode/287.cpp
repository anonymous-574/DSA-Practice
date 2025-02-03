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
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> hold;
        for (int i : nums) {
            if (hold.find(i) != hold.end()) {
                return i;
            } else {
                hold.insert(i);
            }
        }
        return -1;
    }
};


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int s1=nums[0],s2=0,f3=nums[nums[0]];
        while (s1!=f3){
            s1=nums[s1];
            f3=nums[nums[f3]];
        }
        
        while (s1!=s2){
            s1=nums[s1];
            s2=nums[s2];
        }
        
    return s2;
    }
};