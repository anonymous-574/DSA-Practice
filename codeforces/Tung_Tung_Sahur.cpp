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

vector<pair<char, int>> runLength(string &str) {
    vector<pair<char, int>> res;
    int n = str.length();
    int i = 0;
    while (i < n) {
        char c = str[i];
        int count = 0;
        while (i < n && str[i] == c) {
            count++;
            i++;
        }
        res.push_back({c, count});
    }
    return res;
}

void solve(string p, string s) {
    vector<pair<char, int>> a = runLength(p);
    vector<pair<char, int>> b = runLength(s);

    if (a.size() != b.size()) {
        cout << "NO\n";
        return;
    }

    for (int i = 0; i < a.size(); i++) {
        if (a[i].first != b[i].first) {
            cout << "NO\n";
            return;
        }
        if (b[i].second < a[i].second || b[i].second > 2 * a[i].second) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    string p,s;
    for (int t = 1; t <= tc; t++) {
        cin>>p>>s;
        solve(p,s);
    }
}