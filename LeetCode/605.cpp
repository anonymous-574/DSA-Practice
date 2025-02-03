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
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

        if (flowerbed.size() == 1) {
            if (flowerbed[0] == 0) {
                return (n <= flowerbed.size()) ? true : false;
            }
            return (n < flowerbed.size()) ? true : false;
        }

        int ans = 0;
        if (flowerbed.size() > 1 && flowerbed[0] == 0 && flowerbed[1] == 0) {
            ans++;
            flowerbed[0] = 1;
        }

        if (flowerbed.size() > 1 && flowerbed[flowerbed.size() - 1] == 0 &&
            flowerbed[flowerbed.size() - 2] == 0) {
            ans++;
            flowerbed[flowerbed.size() - 1] = 1;
        }

        for (int i = 1; i < flowerbed.size() - 1; i++) {
            if (flowerbed[i - 1] == 0 && flowerbed[i] == 0 &&
                flowerbed[i + 1] == 0) {
                flowerbed[i] = 1;
                ans++;
            }
        }
        return (ans >= n) ? true : false;
    }
};