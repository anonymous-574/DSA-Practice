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
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area = 0, temp = 0;
        queue<pair<int, int>> q;
        int x, y;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    q.push(make_pair(i, j));
                    grid[i][j] = 0;
                    while (!q.empty()) {
                        x = q.front().first;
                        y = q.front().second;
                        q.pop();
                        temp++;

                        if (x - 1 >= 0 && grid[x - 1][y] == 1) {
                            grid[x - 1][y] = 0;
                            q.push(make_pair(x - 1, y));
                        }
                        if (y - 1 >= 0 && grid[x][y - 1] == 1) {
                            grid[x][y - 1] = 0;
                            q.push(make_pair(x, y - 1));
                        }
                        if (x + 1 < grid.size() && grid[x + 1][y] == 1) {
                            grid[x + 1][y] = 0;
                            q.push(make_pair(x + 1, y));
                        }
                        if (y + 1 < grid[i].size() && grid[x][y + 1] == 1) {
                            grid[x][y + 1] = 0;
                            q.push(make_pair(x, y + 1));
                        }
                    }
                    area = max(area, temp);
                    temp = 0;
                }
            }
        }
        return area;
    }
};