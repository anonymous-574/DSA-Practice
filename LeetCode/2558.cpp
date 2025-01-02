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
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq(gifts.begin(),gifts.end());

        int curr;
        for (int i = 0; i < k; i++)
        {
            curr=pq.top();
            pq.pop();
            curr=sqrt(curr);
            pq.push(curr);
        }
        
        long long sum = 0;
        while (!pq.empty()) {
            sum += pq.top(); 
            pq.pop();        
        }
    return sum;
    }
};
