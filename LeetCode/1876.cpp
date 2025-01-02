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
    int countGoodSubstrings(string s) {
        
        int ans=0;

        if (s.length()<2)
        {
            return 1;
        }
        

        for (int i = 0; i < s.length()-2; i++)
        {
            if (s[i]!=s[i+1] && s[i]!=s[i+2] &&s[i+1]!=s[i+2])
            {
                ans++;
            }
            
        }
        return ans;
    }
};

//we can also do with sliding window or hashing