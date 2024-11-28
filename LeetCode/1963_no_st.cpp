#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minSwaps(string s) {
        /*
        int bal=0;
        int swap=0;
        vector<char> v(s.begin(), s.end());
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i]=='[')
            {
                bal++;
            }
            else
            {
                bal--;
            }

            if (bal<0)
            {
                swap++;
                
                auto it = find(v.rbegin(), v.rend(), '[');
                int res = -1;
                if (it != v.rend()) {
                // Calculate the index of the last occurrence
                res = v.rend() - it - 1;
                }
                v[res]=']';
                v[i]='[';
                bal=0;
                i--;
                
            }
            
            
            
        }
    return swap;   
    */

        int open=0,close=0,swap=0;
        vector<char> v(s.begin(), s.end());
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i]=='[')
            {
                open++;
            }
            else
            {
                close--;
            }

            if (close>open)
            {
                swap++;
                close--;
                open++;   
            }
            
            
            
        }
    return swap;



    }
};