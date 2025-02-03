#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
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
    int prefixCount(vector<string>& words, string pref) {
        int ans=0;
        for(int i=0 ; i<words.size(); i++){
            //WARNING STARTS_WITH IS C++ 20 onwards
            if(words[i].starts_with(pref)) ans++;
        }
        return ans;
    }
};