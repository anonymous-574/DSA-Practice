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

void solve(int n , vector<ll>temp) {
    ll ans=0, t=0;

    for (int i = 0; i < temp.size(); i++){
        for (int j = 0; j < temp.size(); j++){
            t+=temp[i]^temp[j];
        }
        ans=max(ans,t);
        t=0;
    }
    cout<<ans<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    int n;
    for (int t = 1; t <= tc; t++) {
        cin>>n;
        vector<ll>temp(n);
        for (int i = 0; i < temp.size(); i++){
            cin>>temp[i];
        }
        
        solve(n,temp);
    }
}