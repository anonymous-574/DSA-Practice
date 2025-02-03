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
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int ocolour = image[sr][sc];
        if (ocolour == color) {
            return image;
        }

        queue<pair<int, int>> q;
        q.push(make_pair(sr, sc));
        int x, y;

        //not 100% needed , but an optimisation
        vector<vector<int>> visited(image.size(), vector<int>(image[0].size(), 0));

        while (!q.empty()) {
            x = q.front().first;
            y = q.front().second;
            q.pop();

            if (visited[x][y]){
                continue;
            }
            image[x][y] = color;
            visited[x][y]=1;

            if (x + 1 < image.size() && image[x + 1][y] == ocolour) {
                q.push(make_pair(x + 1, y));
            }
            if (x - 1 >= 0 && image[x - 1][y] == ocolour) {
                q.push(make_pair(x - 1, y));
            }
            if (y + 1 < image[x].size() && image[x][y + 1] == ocolour) {
                q.push(make_pair(x, y + 1));
            }
            if (y - 1 >= 0 && image[x][y - 1] == ocolour) {
                q.push(make_pair(x, y - 1));
            }
        }

        return image;
    }
};