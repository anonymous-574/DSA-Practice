#include <vector>
#include <queue>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        
    long long ans=0;
    int temp=0;
    priority_queue<int>pq(nums.begin(),nums.end());
        for (int j = 0; j < k; j++)
        {
        temp=pq.top();
        ans+=temp;
        pq.pop();
        pq.push((temp+2)/3);
        }
    return ans;    
    }
};

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();