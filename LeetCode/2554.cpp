#include <vector>
#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set <int> ban(banned.begin(),banned.end());

        int ans=0,tempsum=0;
        for (int i = 1; i <= n; i++)
        {
            if (ban.find(i) == ban.end())
            {
                tempsum+=i;
                if (tempsum <=maxSum)
                {   
                    ans++;
                }
                else
                {
                    break;
                }
            }
            else
            {
                continue;
            }
            
            
        }
    return ans;
    }
};