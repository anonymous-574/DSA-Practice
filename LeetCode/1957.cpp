#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    string makeFancyString(string s) {
        string ans="";
        int hits=0;
        int n = s.size();
        if(n==1)
        {
            return s;
        }
        for (int i = 0; i < n-1; i++)
        {
            if (s[i]==s[i+1])
            {
                if (hits==1)
                {
                continue;
                }
                else
                {
                ans+=s[i];
                hits++;
                }
            }
            else
            {
              ans+=s[i];
              hits=0;    
            }         
        }
    ans+=s[n-1];
    return ans;
    }
};


// AYY IS TLE
class Solution {
public:
    string makeFancyString(string s) {
        for (int i = 1; i < s.size()-1; i++)
        {
            if (s[i-1]==s[i] && s[i] ==s[i+1])
            {
                s.erase(s.begin() + i);
                i--;
            }        
        }
    return s;
    }
};