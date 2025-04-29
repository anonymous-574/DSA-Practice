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

void solve(int size, string temp) {
    int cnt_1=0;
    for (int i = 0; i < size; i++){
        if (temp[i]=='1'){
            cnt_1++;
        }
    }
    int ans=0;
    for (int i = 0; i < size; i++){
        if (temp[i]=='1'){
            ans+=(cnt_1-1);
        }
        else {
            ans+=(cnt_1+1);
        }
        
    }
    cout<<ans<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        int size;
        string temp;
        cin>>size;
        cin>>temp;
        solve(size,temp);
    }
}