#include <bits/stdc++.h>
using namespace std;

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    int chk=0;
    for (int i = 0; i < tc; i++){
        cin>>chk;
        if (chk%2==1){
            cout<<"Yes\n";
        }
        else{
           cout<<"No\n";
        }
    }
    
    
    
    return 0;
}