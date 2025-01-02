#include <vector> 
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <queue>
using namespace std;


class Solution {
public:
    bool isThree(int n) {
        if (n==1)
        {
            return false;
        }
        
        int num=0;

        for (int i = 1; i <= n; i++)
        {
            if (n%i==0)
            {
                num++;
            }
            if (num>3)
            {
                return false;
            }
        }

        cout<<num;
        if (num==3)
        {
            return true;
        }
        return false;
        
    }
};