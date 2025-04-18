#include <bits/stdc++.h>
#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

using namespace std;
using vi = vector<int>;


/*
class Solution {
    public:

        bool calc_pairs(unordered_map<int,int>mp,int k){
            int pairs=0;
            for(auto i: mp){
                if (i.second>1){
                    //pairs+=?;
                }
            }
            return pairs>=k;
        }

        long long countGood(vector<int>& nums, int k) {
            unordered_map<int,int>mp;
            long long ans=0;
            for (int i = 0; i < nums.size(); i++){
                mp[nums[i]]++;
            }

            for (int i = 0; i < nums.size(); i++){
                if (calc_pairs(mp,k)){
                    ans++;
                }
                mp[nums[i]]--;
            }
            
        return ans;    
        }
    };
*/

//actual working one - sliding window
class Solution {
    public:
        long long countGood(vector<int>& nums, int k) {
            unordered_map<int, int> freq;  // Kakashi’s memory sharing scroll
            long long ans = 0, pairs = 0;
            int left = 0;
    
            // Naruto keeps running ahead
            for (int right = 0; right < nums.size(); ++right) {
                int val = nums[right];
    
                // Count how many shadow clones already exist for this value
                pairs += freq[val];
                freq[val]++;
    
                // If pair count is enough, shrink from the left
                while (pairs >= k) {
                    ans += nums.size() - right;  // All endings from here are good
                    int out = nums[left++];
                    freq[out]--;
                    pairs -= freq[out]; // Reduce support from outgoing value
                }
            }
            return ans;
        }
    };