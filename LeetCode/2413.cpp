#include <vector> 
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    int smallestEvenMultiple(int n) {
        if(n%2==0)
        {
            return n;
        }
        else
        {
            return n*2;
        }
    }
};