#include <vector> 
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
    int max_i=values[0]+0;
    int max_sc=0;

    for (int i = 1; i < values.size(); i++)
    {
        max_sc=max(max_sc,max_i+values[i]-i);
        max_i=max(max_i,values[i]+i);
    }
    return max_sc;
    }
};