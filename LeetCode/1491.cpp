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
    double average(vector<int>& salary) {
        int maxs=INT_MIN,mins=INT_MAX;

        double sum=0;
        for (int i = 0; i < salary.size(); i++)
        {
            maxs=max(maxs,salary[i]);
            mins=min(mins,salary[i]);
            sum+=salary[i];
        }
        return (sum-maxs-mins)/(salary.size()-2);
    }
};