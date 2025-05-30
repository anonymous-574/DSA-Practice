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
    int firstUniqChar(string s) {
        
        vector<int>v(26,0);
        for (int i = 0; i < s.size(); i++){
            v[s[i]-'a']++;
        }        

        for (int i = 0; i < s.size(); i++){
            if (v[s[i]-'a']==1){
                return i;
            }
        }
    return -1;
    }
};