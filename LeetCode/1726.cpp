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


//VERY VERY CURSED
class Solution {
public:
    struct pair_hash {
        template <class T1, class T2>
        std::size_t operator()(const std::pair<T1, T2>& p) const {
            auto h1 = std::hash<T1>{}(p.first);
            auto h2 = std::hash<T2>{}(p.second);
            return h1 ^ (h2 << 1); // Combine the hashes
        }
    };

    int tupleSameProduct(vector<int>& nums) {
        int ans = 0;
        // pair -> int
        unordered_map<pair<int, int>, int, pair_hash> mp;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                mp[make_pair(nums[i], nums[j])] = nums[i] * nums[j];
                for (const auto& entry : mp) {
                    if (entry.second == nums[i] * nums[j] &&
                        !(entry.first.first == nums[i] &&
                          entry.first.second == nums[j])) {
                        ans++;
                    }
                }
            }
        }

        return ans * 8;
    }
};

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        //product , frequency
        unordered_map<int,int>mp;

        for (int i = 0; i < nums.size(); i++){
            for (int j = i+1; j < nums.size(); j++){
                mp[nums[i]*nums[j]]++;
            }
        }
        int ans=0;
        
        int pairs_of_equal_prod=0;
        // this is valid
        //what version of cpp?
        for (auto [value,frequency] : mp){
            pairs_of_equal_prod=(frequency-1)*frequency/2;
            ans+=8*pairs_of_equal_prod;
        }
        

    return ans;
    }
};