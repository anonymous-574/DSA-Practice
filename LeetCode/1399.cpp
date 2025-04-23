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

void solve() {
}

class Solution {
    public:
        int sumOfDigits(int n) {
        int sum = 0;
        while (n != 0) {
            int last = n % 10;
            sum += last;
            n /= 10;
        }
        return sum;
        }
    
        int countLargestGroup(int n) {
            vector<int> sum (37,0);
    
            for(int i=1; i<=n; i++){
                sum[sumOfDigits(i)]++;
            }
    
            int grp_size = *max_element(sum.begin(), sum.end());
            int ans=0;
    
            for(int i:sum){
                if(i==grp_size){
                    ans++;
                }
            }
        return ans;
        }
    };