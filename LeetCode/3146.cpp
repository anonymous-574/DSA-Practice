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
    int findPermutationDifference(string s, string t) {
        
        unordered_map<char,int> s1;
        unordered_map<char,int> t1;

        for (int i = 0; i < s.length(); i++)
        {
            s1.insert(make_pair(s[i],i));
            t1.insert(make_pair(t[i],i));
        }

        int ans=0;
        for (int i = 0; i < s.length(); i++)
        {
            ans+=abs(s1[s[i]]-t1[s[i]]);
        }
    return ans;
    }
};