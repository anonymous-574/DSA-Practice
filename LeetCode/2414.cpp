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
        int longestContinuousSubstring(string s) {
            char curr = s[0];
            int ans = 1, final = 1;
            ;
            for (int i = 1; i < s.length(); i++) {
                if (s[i] == curr + 1) {
                    ans++;
                    final = max(ans, final);
                    curr++;
                } else {
                    curr = s[i];
                    ans = 1;
                }
            }
            return final;
        }
    };