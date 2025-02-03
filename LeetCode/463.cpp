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
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans=0;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[i].size(); j++){
             if (grid[i][j]==1){

             if (j+1>=grid[i].size() || grid[i][j+1]==0){
                ans++;
             }
             if (i+1>=grid.size() || grid[i+1][j]==0){
                ans++;
             }
             if (i-1<0 || grid[i-1][j]==0){
                ans++;
             }
             if (j-1<0 || grid[i][j-1]==0){
                ans++;
             }
            }
            }
        }
    return ans;           
    }
};