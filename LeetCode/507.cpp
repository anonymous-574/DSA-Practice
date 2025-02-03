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
    bool checkPerfectNumber(int num) {
        int sum=0;
        for(int i=1; i<=num/2; i++){
            if(num%i==0){sum+=i;}
        } 
        return sum==num;
    }
};