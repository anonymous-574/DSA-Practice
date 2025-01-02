#include <vector> 
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        int ch = (int)coordinate1[0]-96;
        int num = coordinate1[1] - '0';
        
        int ch1 = (int)coordinate2[0]-96;
        int num1 = coordinate2[1] - '0';

        if ( (ch+num)%2 ==(ch1+num1)%2)
        {
            return true;
        }
        return false;
        
    }
};