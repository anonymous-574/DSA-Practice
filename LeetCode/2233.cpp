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
    int maximumProduct(vector<int>& nums, int k) {
        
        priority_queue <int, vector<int>, greater<int>> pq(nums.begin(),nums.end());

        int curr;
        for (int i = 0; i < k; i++)
        {
            curr=pq.top();
            pq.pop();
            curr++;
            pq.push(curr);
        }
        
        long long ans1=1;
        while(!pq.empty())
        {
            ans1= (ans1 % (1000000007) * pq.top() %(1000000007)) %(1000000007);
            pq.pop();
        }
        int ans=(int)ans1;
        return ans;
    }
};