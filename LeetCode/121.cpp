#include <vector> 
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=prices[0];
        int profit=0;

        for (int i = 0; i < prices.size(); i++)
        {
            buy=min(buy,prices[i]);
            profit=max(profit,prices[i]-buy);
        }
        
    return profit;
    }
};