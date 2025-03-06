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


//Brute force
class Solution {
    public:
        vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
            int a, b;
            int size = grid.size();
            unordered_set<int> hold;
    
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    if (hold.find(grid[i][j]) != hold.end()) {
                        a = grid[i][j];
                    } else {
                        hold.insert(grid[i][j]);
                    }
                }
            }
    
            for (int i = 1; i <= size * size; i++) {
                if (hold.find(i) == hold.end()) {
                    b = i;
                }
            }
            return {a, b};
        }
    };

//Optimised a lot
class Solution {
    public:
        vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
            int n = grid.size();
            int missing = -1, repeat = -1;
    
            // Store frequency of each number in the grid
            unordered_map<int, int> freq;
            for (auto& row : grid) {
                for (int num : row) {
                    freq[num]++;
                }
            }
    
            // Check numbers from 1 to n^2 to find missing and repeated values
            for (int num = 1; num <= n * n; num++) {
                if (!freq.count(num)) {
                    missing = num;  // Number not present in grid
                } else if (freq[num] == 2) {
                    repeat = num;  // Number appears twice
                }
            }
    
            return {repeat, missing};
        }
    };

//Best solution
