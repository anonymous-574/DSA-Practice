#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <limits>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(string s) {
        
        int sum1=0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i]=='1')
            {
                sum1++;
            }
        }

        
        int score=0,sum0=0;

        for (int i = 0; i < s.length()-1; i++)
        {
            if (s[i]=='0')
            {
                sum0++;
            }
            else
            {
                sum1--;
            }
            score=max(score,sum0+sum1);  
        }
        return score;
    }
};

/*
Step 1: Loop to count the total digit 1 on a string. Call sumOne
Step 2: Init sumZero = 0. Loop again, if the current position is 0, sumZero++. 
Otherwise, sumOne--. maxScore = max(maxScore, sumZero + sumOne)
ps. in second step the loop iterate from 0 to size()-1 this is because if there is a case "00" 
then your answer should be 1 not 2 so if you iterate the full string you result into wrong answer
*/