#include <vector>
#include <iostream>
#include <bits/stdc++.h>
#include <unordered_set> 
#include <numeric>
using namespace std;

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        unordered_set <int> nodes;
        vector<int> vec(n);
        iota(vec.begin(), vec.end(), 0);
        for (int i = 0; i < edges.size(); i++)
        {
            if (nodes.find(edges[i][1])==nodes.end())
            {
                //element not found
                nodes.insert(edges[i][1]);
            }
        }

        vec.erase(
        remove_if(vec.begin(), vec.end(),
            [&nodes](int num) { return nodes.count(num) > 0; }),
        vec.end()
        );

        if (vec.size()>1)
        {
            return -1;
        }
        else
        {
            return vec[0];
        } 
    }
};