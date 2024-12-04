#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    char increment(char a)
    {
        if (a=='z')
        {
            return 'a';
        }
        else
        {
            return a+1;
        }
        
        
    }

    bool canMakeSubsequence(string str1, string str2) {
        
        if (str2.size()>str1.size())
        {
            return false;
        }
        
        int i=0,j=0;
        while (i<str1.size() && j<str2.size())
        {
            if (str1[i]==str2[j] || increment(str1[i])==str2[j])
            {
                i++;
                j++;
            }
            else
            {
                i++;
            }        
        }
        
        if (j==str2.size())
        {
            return true;
        }
        else
        {
            return false;
        }
        

    }
};