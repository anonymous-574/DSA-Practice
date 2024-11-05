#include <vector>
#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        if (chars.size()==1)
        {
            return chars.size();
        }
        
        
        int cnt=1;
        for (int i = 0; i < chars.size()-1; i++)
        {
            if (chars[i]==chars[i+1])
            {
                chars.erase(chars.begin() + i+1);
                cnt++;
            }
            else if(cnt!=1)
            {
                chars.insert(chars.begin() + i+1, cnt);
                cnt=1;
            }
            else
            {
                cnt=1;
            }
            
            
        }
        
    }
};