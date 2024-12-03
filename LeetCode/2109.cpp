#include <vector>
#include <iostream>
#include <bits/stdc++.h> 
#include <string>
using namespace std;


class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string output;
        int temp=0;
        for (int i = 0; i < s.size(); i++)
        {
            if (temp< spaces.size() && spaces[temp]==i)
            {                
                output+=' ';
                temp++;
            }
            output+=s[i];
        }
        
    return output;
    }
};