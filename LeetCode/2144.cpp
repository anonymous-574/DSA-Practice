#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& cost) {
    
        sort(cost.begin(),cost.end());
        int pay=0;
        int temp=0;
        for (int i = cost.size()-1; i >=0; i--)
        {
            if (temp==2)
            {
                //its free enjoy
                temp=0;
                continue;
            }
            pay+=cost[i];
            temp++;
        }
        
    return pay;
    }
};