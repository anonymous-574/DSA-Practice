#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {

        vector<pair<int, int>> ppl;

        for (int i = 0; i < logs.size(); i++) {
            ppl.push_back(make_pair(logs[i][0], 0));
            ppl.push_back(make_pair(logs[i][1], 1));
        }

        std::sort(
            ppl.begin(), ppl.end(),
            [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
                return (a.first < b.first) ||
                       (a.first == b.first && a.second > b.second);
            });

        int max_pop = INT_MIN;
        int alive = 0;
        vector<pair<int, int>> year;

        for (int i = 0; i < ppl.size(); i++) {
            if (ppl[i].second == 0) {
                alive++;
                max_pop = max(max_pop, alive);
                year.push_back(make_pair(ppl[i].first, alive));
            } else {
                alive--;
                year.push_back(make_pair(ppl[i].first, alive));
            }
        }

        for (int i = 0; i < year.size(); i++) {
            if (year[i].second == max_pop) {
                return year[i].first;
            }
        }

        return 0;
    }
};