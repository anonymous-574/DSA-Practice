#include <vector>
#include <iostream>
#include <bits/stdc++.h> 
#include <stack>
using namespace std;

class Solution {
public:
    int minLength(string s) {

    stack <char> st;
    //you can create a stack, then scan the string, put all char you meet into stack, 
    //and once meet "B" or "D", check whether the top of stack is "A" or "B", if so, 
    //pop it and increase 1, if not, push "B" or "D" into stack, then continously scan the string.
    for (int i = 0; i < s.size(); i++)
    {
        if (st.empty()) {
            st.push(s[i]);
            continue;
            }
        if ((s[i]=='B' && st.top()=='A') ||  (s[i]=='D' &&st.top()=='C'))
        {
            cout<<st.top()<<endl;
            st.pop();
        }
        else
        {
        st.push(s[i]);
        }
    }
    return st.size();
    }
};