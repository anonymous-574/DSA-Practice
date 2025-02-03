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
    string finalString(string s) {
        string ans="";
        
        for(int i=0; i<s.length();i++){
            if(s[i]=='i'){
                reverse(ans.begin(), ans.end());
            }
            else{
                ans+=s[i];
            }
        
    }
    return ans;
    }
};