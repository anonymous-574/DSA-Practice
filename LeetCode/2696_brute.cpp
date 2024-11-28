#include <vector>
#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int minLength(string s) {
        vector <char> v(s.begin(), s.end());
        int size=v.size();
    
        if(size==0)
        {
            return 0;
        }
        else if(size==1)
        {
            return 1;
        }
       for (int i = 0; i < size-1; i++)
        {
            if ((v[i]=='A' && v[i+1]=='B') || (v[i]=='C' && v[i+1]=='D'))
            {
                cout<<i<<endl;
                cout<<v[i]<<endl;
                cout<<v[i+1]<<endl;
                v.erase(v.begin() + i);
                v.erase(v.begin() + i);
                if (i>=2)
                {
                    i-=2;
                }
                else if (i==1)
                {
                    i--;
                }
                string str(v.begin(), v.end());
                minLength(str);            
            }
        }
        
        if (size==2 && (v[0]=='A'&& v[1]=='B') || (v[0]=='C'&&v[1]=='D'))
        {
            v.erase(v.begin());
            v.erase(v.begin());
        }
    

        return v.size();
    }
};