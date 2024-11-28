#include <vector> 
#include <iostream>
#include <bits/stdc++.h>
#include <stack>
using namespace std;
/*
class Solution {
public:
    int minAddToMakeValid(string s) {

        stack <char> st;
        int size=0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i]=='(')
            {
                st.push(s[i]);
            }
            else if (!st.empty() && st.top()=='(')
            {
                st.pop();
            }
            else if (st.empty())
            {
                size++;
            }   
        }
    return st.size()+size;
    }
};
*/

class Solution {
public:
    int minAddToMakeValid(string s) {
        int openBrackets = 0;

        int minAddsRequired = 0;
        for (char c : s) {
            if (c == '(') {
                openBrackets++;
            } else {
                // If open bracket exists, match it with the closing one
                // If not, we need to add a open bracket.
                openBrackets > 0 ? openBrackets-- : minAddsRequired++;
            }
        }

        // Add the remaining open brackets as closing brackets would be
        // required.
        return minAddsRequired + openBrackets;
    }
};