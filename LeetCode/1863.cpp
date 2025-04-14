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

class Solution {
    public:
    
        void subsetRecur(int i, vector<int>& arr, vector<vector<int>>& res, vector<int>& subset) {
        
            if (i == arr.size()) {
                res.push_back(subset);
                return;
            }
    
            subset.push_back(arr[i]);
            subsetRecur(i+1, arr, res, subset);
    
            subset.pop_back();
            subsetRecur(i+1, arr, res, subset);
        }
    
        vector<vector<int> > subsets(vector<int>& arr) {
            vector<int> subset;
            vector<vector<int>> res;
            subsetRecur(0, arr, res, subset);
            return res;
        }
    
    
        int subsetXORSum(vector<int>& nums) {
            vector<vector<int> > res = subsets(nums);
    
            int ans=0, temp_xor=0;
            for(int i=0; i<res.size(); i++){
                if(res[i].empty()){
                    continue;
                }
                temp_xor=res[i][0];
                for(int j=1; j<res[i].size(); j++){
                    temp_xor=temp_xor^res[i][j];
                }
                ans+=temp_xor;
            }
            return ans;
        }
    };