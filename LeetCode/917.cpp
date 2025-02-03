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
    string reverseOnlyLetters(string s) {
        int i=0,j=s.length()-1;

        while (i<j)
        {
            if ( (s[i]>=65 && s[i]<=90) ||(s[i]>=97 &&s[i]<=122) && (s[j]>=65 && s[j]<=90) ||(s[j]>=97 &&s[j]<=122)){
                swap(s[i],s[j]);
            }
            
            if (!(s[i]>=65 && s[i]<=90) ||(s[i]>=97 &&s[i]<=122)){
                i++;
            }
            if (!(s[j]>=65 && s[j]<=90) ||(s[j]>=97 &&s[j]<=122)){
                j--;
            }
            
        }
    return s;
    }
};