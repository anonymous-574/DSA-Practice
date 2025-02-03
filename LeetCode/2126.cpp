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
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long temp = mass;

        sort(asteroids.begin(), asteroids.end());
        for (int i : asteroids) {
            if (temp >= i) {
                temp += i;
            } else {
                return false;
            }
        }

        return true;
    }
};