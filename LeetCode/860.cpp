#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <limits>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {

        int change_5 = 0;
        int change_10 = 0;

        for (int i = 0; i < bills.size(); i++) {
            if (bills[i] == 5) {
                change_5++;
            } else if (bills[i] == 10) {
                if (change_5 > 0) {
                    change_5--;
                    change_10++;
                    continue;
                }
                return false;
            } else {
                if (change_10 > 0 && change_5 > 0) {
                    change_10--;
                    change_5--;
                    continue;
                } else if (change_5 >= 3) {
                    change_5 -= 3;
                    continue;
                }
                return false;
            }
        }

        return true;
    }
};