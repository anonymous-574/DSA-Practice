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

void solve(int n,int k, vector<int>a, vector<int>b) {
    int x;
    int is_all_neg=1;
    for (int i = 0; i < a.size(); i++){
        if (b[i]!=-1){
            x=a[i]+b[i];
            is_all_neg=0;
            break;
        }
    }

    if (is_all_neg){
        int l = a[0], r = a[0] + k;
        for (int i = 1; i < n; i++) {
            l = max(l, a[i]);
            r = min(r, a[i] + k);
        }
        if (l > r) cout << 0 << '\n';
        else cout << r - l + 1 << '\n';
    }
    else{
        for (int i = 0; i < b.size(); i++){
            if (b[i]==-1 && ( x-a[i]<0 || x-a[i]>=k)){
                cout<<"0"<<endl;    
                return;    
            }     
        }
        cout<<"1"<<endl;        

    }
    

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        int n,k;
        cin>>n;
        cin>>k;
        vector<int>a(n),b(n);
        for (int i = 0; i < n; i++){
            cin>>a[i];
        }
        for (int i = 0; i < n; i++){
            cin>>b[i];
        }
        solve(n,k,a,b);
    }
}