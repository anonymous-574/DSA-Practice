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
        int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
            int ans = 0;
    
            for (int i = 0; i < arr.size(); i++) {
                for (int j = i + 1; j < arr.size(); j++) {
                    for (int k = j + 1; k < arr.size(); k++) {
                        if ((abs(arr[i] - arr[j]) <= a) &&
                            (abs(arr[j] - arr[k]) <= b) &&
                            (abs(arr[i] - arr[k]) <= c)) {
                            ans++;
                        }
                    }
                }
            }
            return ans;
        }
    };