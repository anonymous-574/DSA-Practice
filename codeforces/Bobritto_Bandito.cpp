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

void solve(int n , int m , int l, int r) {
    int ans_l=0,ans_r=0;

    if (n==m){
        cout<<l<<" "<<r<<endl;
        return;
    }
    
    while (m>0 && ans_r<r){
        m--;
        ans_r++;
    }
    
    while (m>0 && ans_l>l){
        m--;
        ans_l--;
    }
    cout<<ans_l<<" "<<ans_r<<endl;
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    int n,m,l,r;
    for (int t = 1; t <= tc; t++) {
        cin>>n>>m>>l>>r;
        solve(n,m,l,r);
    }
}