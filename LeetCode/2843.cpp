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

class Solution {
    public:
        int countSymmetricIntegers(int low, int high) {
            int ans = 0;
            for (int i = low; i <= high; i++) {
                string temp = to_string(i);
                int x_sum = 0, y_sum = 0;
                int x = 0, y = temp.length() - 1;
    
                if (y % 2 == 0) {
                    continue;
                }
                while (x < y) {
                    x_sum += temp[x] - '0';
                    y_sum += temp[y] - '0';
                    x++;
                    y--;
                }
                if (x_sum == y_sum && i > 9) {
                    ans++;
                }
            }
    
            return ans;
        }
    };

    class Solution {
        public:
            int countSymmetricIntegers(int low, int high) {
                int res = 0;
                for (int a = low; a <= high; ++a) {
                    if (a < 100 && a % 11 == 0) {
                        res++;
                    } else if (1000 <= a && a < 10000) {
                        int left = a / 1000 + (a % 1000) / 100;
                        int right = (a % 100) / 10 + a % 10;
                        if (left == right) {
                            res++;
                        }
                    }
                }
                return res;
            }
        };