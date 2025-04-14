/*Bad tle 

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

int calc_rizz(vector<int>p){
    int ans=0;
    for (int i = 0; i < p.size(); i++){
        ans+=p[i]*(i+1);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    int q,s,k;
    vector<int>ans;
    for (int t = 1; t <= tc; t++) {
        cin>>q;
        for (int i = 0; i < q; i++){
            cin>>s;
            if (s==1){
                //cyclic shift
                rotate(ans.rbegin(), ans.rbegin() + 1, ans.rend());
            }
            else if (s==2){
                //reverse
                reverse(ans.begin(), ans.end());
            }
            else{
                cin>>k;
                ans.push_back(k);
            }
            int rizz=calc_rizz(ans);
            cout<<rizz<<endl;
            
        }
        
    }
}




*/




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

int calc_rizz(vector<int>p){
    int ans=0;
    for (int i = 0; i < p.size(); i++){
        ans+=p[i]*(i+1);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int q;
        cin >> q;

        deque<int> dq;
        bool rev = false;
        ll rizz = 0;

        for (int i = 0; i < q; i++) {
            int op;
            cin >> op;

            if (op == 1) {
                if (!dq.empty()) {
                    if (!rev) {
                        int last = dq.back();
                        dq.pop_back();
                        dq.push_front(last);
                    } else {
                        int first = dq.front();
                        dq.pop_front();
                        dq.push_back(first);
                    }
                }
            }
            else if (op == 2) {
                // Reverse
                rev = !rev;
            }
            else {
                int k;
                cin >> k;
                if (!rev) dq.push_back(k);
                else dq.push_front(k);
            }

            ll current_rizz = 0;
            int pos = 1;
            if (!rev) {
                for (int val : dq) {
                    current_rizz += 1LL * val * pos;
                    pos++;
                }
            } else {
                for (auto it = dq.rbegin(); it != dq.rend(); ++it) {
                    current_rizz += 1LL * (*it) * pos;
                    pos++;
                }
            }
            cout << current_rizz << '\n';
        }
    }
}