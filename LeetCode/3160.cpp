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
        vector<int> queryResults(int limit, vector<vector<int>>& queries) {
            vector<int> ans(queries.size());
    
            // colour,freq
            // color map
            //  colour 1 -> 5 instances etc ...
    
            // ball map
            // ball 1 ->colour 1
    
            // every time the colour changes in ball map, update colour map
            unordered_map<int, int> color_map, ball_map;
            int ball, color;
            for (int i = 0; i < queries.size(); i++) {
                ball = queries[i][0];
                color = queries[i][1];
    
                if (ball_map.find(ball) != ball_map.end()) {
                    int prev_color = ball_map[ball];
                    color_map[prev_color]--;
    
                    if (color_map[prev_color] == 0) {
                        color_map.erase(prev_color);
                    }
                }
                ball_map[ball] = color;
                color_map[color]++;
                ans[i] = color_map.size();
            }
    
            return ans;
        }
    };