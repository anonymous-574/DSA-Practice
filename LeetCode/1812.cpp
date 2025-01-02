#include <vector> 
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    bool squareIsWhite(string coordinates) {
        int ch = (int)coordinates[0]-96;
        int num = coordinates[1] - '0';
        
        if (ch%2==num%2)
        {
            return false;
        }
        return true;  
    }
};