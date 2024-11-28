#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h> 
#include <stack>
using namespace std;

class Solution {
public:

    char evaluate(vector<char> c , char op)
    {   
        if (op=='&')
        {
            for (int i = 0; i < c.size(); i++)
            {
                if (c[i]=='f')
                {
                    return 'f';
                }
                
            }
            return 't';
        }
        else if (op=='|')
        {
            for (int i = 0; i < c.size(); i++)
            {
                if (c[i]=='t')
                {
                    return 't';
                }
                
            }
            return 'f';
        }
        else
        {
            if (c[0]=='t')
            {
                return 'f';
            }
            else
            {
                return 't';
            }
            
            
        }
        
        
        
    }

    bool parseBoolExpr(string expression) {
        stack <char> st;
        vector <char> to_eval;
        char op;
        for (int i = 0; i < expression.size(); i++)
        {
            if (expression[i]==')')
            {
                while (st.top()!='(')
                {
                    to_eval.push_back(st.top());
                    st.pop();
                }
                //the opening bracket
                st.pop();

                op=st.top();
                st.pop();
                st.push(evaluate(to_eval,op));
                to_eval.clear();
            }
            else if( expression[i]!=',')
            {
                st.push(expression[i]);
            }
            
            
        }
    
     return (st.top() == 't') ? true : (st.top() == 'f' ? false : false);
    }
};