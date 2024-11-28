#include <vector>
#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    string compressedString(string word) {
        string ans="";
        int cnt=1;
        for (int i = 0; i < word.size(); i++)
        {
            if (word[i]==word[i+1])
            {
                cnt++;
                if (cnt>9)
                {
                    ans+=(char)cnt-1+'0';
                    ans+=word[i];
                    cnt=1;
                }            
            }
            else
            {
                ans+=(char)cnt+'0';
                ans+=word[i];
                cnt=1;
            }
        }
    return ans; 
    }
};