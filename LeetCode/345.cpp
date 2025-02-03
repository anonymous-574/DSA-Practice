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
    string reverseVowels(string s) {
        int i=0,j=s.length()-1;
        unordered_set<char> vov{'a','e','i','o','u','A','E','I','O','U'};

        while (i<j){
            while (i<j && vov.find(s[i]) == vov.end()){
                i++;
            }
            while (i<j && vov.find(s[j]) == vov.end()){
                j--;
            }
            if (i<j){
                swap(s[i],s[j]);
                i++;
                j--;
            }                  
        }
    return s; 
    }
};