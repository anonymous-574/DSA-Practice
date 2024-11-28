#include <vector>
#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans="";

        //to append use +=
        
        //Always use the char with current max count.
        //If it is not valid (check two previous position), try char with next count. 
        //If there is no next count, we can return at that point.

        char curmax=' ';
        int cnt_a=0,cnt_b=0,cnt_c=0;
        int size=a+b+c;


        
        for (int i = 0; i < size; i++)
        {        
        
        if ((a >= b and a >= c and cnt_a != 2) or (a > 0 and (cnt_b == 2 or cnt_c == 2))) {
            ans+='a';
            cnt_b=0;
            cnt_c=0;
            a--;
        }
        else if ((b >= a and b >= c and cnt_b != 2) or (b > 0 and (cnt_a == 2 or cnt_c == 2))) {
            ans+='b';
            cnt_a=0;
            cnt_c=0;
            b--;
        }
        else if ((c >= b and c >= a and cnt_c != 2) or (c > 0 and (cnt_b == 2 or cnt_a == 2))) {
            ans+='c';
            cnt_b=0;
            cnt_a=0;
            c--;
        }
        
        }
        
        /*
        for (int i = 0; i < size; i++)
        {
        //step 1 mind max of a,b,c
        if (a >= b) {
        if (a >= c)
        {
            curmax='a';
            cnt_a++;
        }
        else
        {
            curmax='c';
            cnt_c++;
        }
        }
        else {
        if (b >= c)
        {
            curmax='b';
            cnt_b++;
        }
        else
        {
            curmax='c';
            cnt_c++;
        }
        }

        cout<<curmax<<endl;
        
        if (curmax='a' and cnt_a<2)
        {
            a--;
            ans+=curmax;
            cnt_b=0;
            cnt_c=0;
        }
        else if (curmax='b' and cnt_b<2)
        {
            b--;
            ans+=curmax;
            cnt_a=0;
            cnt_c=0;
        }
        else if (curmax='c' and cnt_c<2)
        {
            c--;
            ans+=curmax;
            cnt_a=0;
            cnt_b=0;
        }
        else
        {
            cout<<"FAIL?"<<endl;
            continue;
        }

        }
        */

        
        
        


        
    return ans;  
    }
};