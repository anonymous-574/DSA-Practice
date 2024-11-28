#include <vector>
#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    long long minimumSteps(string s) {
        
        int cnt_0=0;
        long long ans=0;
        for (int i = s.length(); i >=0; i--)
        {
            if (s[i]=='0')
            {
                cnt_0++;
            }
            else
            {
                ans+=cnt_0;
            }        
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