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
    char findTheDifference(string s, string t) {
        
        vector<int> s1(26,0);
        vector<int> t1(26,0);

        //load all chars from string to vector
        for (char c : s) {
            s1[c - 'a']++;
        }

        for (char c : t) {
            t1[c - 'a']++;
        }

        for (int i = 0; i < s1.size(); i++){
            if (s1[i]!=t1[i]){
                //return that char
                return 'a' + i;
            }
            
        }
        
    return ' ';
    }
};