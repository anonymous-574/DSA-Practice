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
        int findNumbers(vector<int>& nums) {
            int ans=0;
            for(int i: nums){
                int n=floor(log10(i) + 1);
                if (n%2==0){
                    ans++;
                }
            }
        return ans;
        }
    };