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

void solve(int n , int x) {
    
    for (int i = x+1; i < n; i++){
        cout<<i<<" ";
    }

    for (int i = 0; i < x; i++){
        cout<<i<<" ";
    }

    cout<<x<<endl;

    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        int n,x;
        cin>>n;
        cin>>x;
        solve(n,x);
    }
}