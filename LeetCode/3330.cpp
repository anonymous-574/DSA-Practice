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
    int possibleStringCount(string word) {
        
    int ans=1;

    for (int i = 0; i < word.length()-1; i++){
        if (word[i]==word[i+1]){
            ans++;
        }
        
    }
    
    return ans;
    }
};