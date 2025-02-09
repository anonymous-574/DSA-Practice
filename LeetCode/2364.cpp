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

//TLE
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long ans = 0;
        int itr = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (j - i == nums[j] - nums[i]) {
                    ans++;
                }
                itr++;
            }
        }

        return itr - ans;
    }
};


//MY
class Solution {
    public:
        long long countBadPairs(vector<int>& nums) {
            // value nums[i] - i, indexes
            unordered_map<int, vector<int>> mp;
            long long n = nums.size();
    
            for (int i = 0; i < n; i++) {
                mp[nums[i] - i].push_back(i);
            }
    
            long long good = 0;
            // number of iterations in 2 for loops for i<j is n(n-1)/2 for n>1
            for (auto i : mp) {
                if (i.second.size() > 1) {
                    good += i.second.size() * (i.second.size() - 1) / 2;
                }
            }
            good = (n * (n - 1) / 2) - good;
            return good;
        }
    };


//same logic as my
//very efficent
class Solution {
    public:
        long long countBadPairs(vector<int>& nums) {
            unordered_map<int, int> freq;
            long long goodPairs = 0, n = nums.size();
            
            for (int i = 0; i < n; i++) {
                int key = nums[i] - i;
                goodPairs += freq[key];
                freq[key]++;
            }
            
            return (n * (n - 1)) / 2 - goodPairs;
        }
    };