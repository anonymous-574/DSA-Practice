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
    int findMaxFish(vector<vector<int>>& grid) {

        int ans = 0;
        int temp = 0;

        queue<pair<int, int>> q;
        int x, y;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] != 0) {
                    q.push(make_pair(i, j));
                    temp += grid[i][j];

                    while (!q.empty()) {
                        x = q.front().first;
                        y = q.front().second;
                        q.pop();
                        grid[x][y] = 0;

                        if (y + 1 < grid[0].size() && grid[x][y + 1] != 0) {
                            q.push(make_pair(x, y + 1));
                            temp += grid[x][y + 1];
                            grid[x][y + 1] = 0;
                        }

                        if (y - 1 >= 0 && grid[x][y - 1] != 0) {
                            q.push(make_pair(x, y - 1));
                            temp += grid[x][y - 1];
                            grid[x][y - 1] = 0;
                        }

                        if (x + 1 < grid.size() && grid[x + 1][y] != 0) {
                            q.push(make_pair(x + 1, y));
                            temp += grid[x + 1][y];
                            grid[x + 1][y] = 0;
                        }

                        if (x - 1 >= 0 && grid[x - 1][y] != 0) {
                            q.push(make_pair(x - 1, y));
                            temp += grid[x - 1][y];
                            grid[x - 1][y] = 0;
                        }
                    }
                    ans = max(temp, ans);
                    temp = 0;
                }
            }
        }

        return ans;
    }
};