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
    int sumOfTheDigitsOfHarshadNumber(int x) {
    int orig =x;
    int sum=0;
    while (x > 0) {
        sum+=x%10;
        x = x / 10;
    }

    if(orig%sum==0) return sum;
    else return -1;

    }
};