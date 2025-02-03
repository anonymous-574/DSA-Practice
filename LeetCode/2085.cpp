#include <vector> 
#include <iostream>
#include <bits/stdc++.h>
#include <unordered_set> 

using namespace std;
    
class Solution {
public:

    int countWords(vector<string>& words1, vector<string>& words2) {
    unordered_map<string,int>mp1,mp2;
    for (string i: words1){
        mp1[i]++;
    }
    for (string i: words2){
        mp2[i]++;
    }
    
    int ans=0;
    for (string i: words1){
        if (mp1[i]==1 && mp2[i]==1){
            ans++;
        }
    }
     return ans;   
    }
};