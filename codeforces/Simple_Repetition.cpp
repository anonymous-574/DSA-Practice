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

bool isPrime(int n) {
    if (n <= 1)
        return false;
    if (n == 2 || n == 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i <= sqrt(n); i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}


void solve(int i,int j){


    if(i==1 && j==2){
        cout<<"Yes\n";
        return;
    }
    
    if (isPrime(i)){
        if (j==1){
            cout<<"Yes\n";
        }
        else{
            cout<<"No\n";
        }
    }
    else{
        cout<<"No\n";
    }
    

    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    int no1,no2=0;
    for (int i = 0; i < tc; i++){
        cin>>no1;
        cin>>no2;
        solve(no1,no2);
    }
    
    
    
    return 0;
}