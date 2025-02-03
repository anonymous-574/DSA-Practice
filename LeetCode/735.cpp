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
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int i = 0; i < asteroids.size(); i++) {
            if (asteroids[i] > 0) {
                st.push(asteroids[i]);
            } else {

                while (!st.empty() && st.top() > 0 &&
                       st.top() < -asteroids[i]) {
                    st.pop();
                }

                if (st.empty() || st.top() < 0) {
                    st.push(asteroids[i]);
                }
                if (!st.empty() && st.top() == -asteroids[i]) {
                    st.pop();
                }
            }
        }

        vector<int> ans(st.size());
        int temp = st.size() - 1;

        while (!st.empty()) {
            ans[temp] = st.top();
            st.pop();
            temp--;
        }

        return ans;
    }
};