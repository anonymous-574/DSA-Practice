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

void solve(int n ,vector<vector<int>>arr ) {
    unordered_set<int>temp;
    vector<int>ans(2*n);
    
    for (int i = 0; i < arr.size(); i++){
        for (int j = 0; j < arr.size(); j++){
            ans[i+j+1]=arr[i][j];
            temp.insert(ans[i+j+1]);
        }
    }
    
    
    for (int i = 1; i <= 2*n; i++){
        if (temp.find(i)==temp.end()){
            ans[0]=i;
            break;
        }
    }
    
    for (int i = 0; i < 2*n; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;


}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    int n;
    for (int t = 1; t <= tc; t++) {
        cin>>n;
        vector<vector<int>>arr(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cin>>arr[i][j];
            }  
        }
        
        solve(n,arr);
    }
}