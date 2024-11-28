#include <vector>
#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int minChanges(string s) {
    int change=0;
    for (int i = 0; i < s.size()-1;i+=2)
    {
        if(s[i]!=s[i+1])
        {
            change++;
        }
    }
    return change;            
    }
};

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();