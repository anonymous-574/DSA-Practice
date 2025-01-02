#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
    int ans=nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            ans=ans^nums[i];
        }
    return ans;
    }
};

/*
xor of two same number is 0
xor is commutative
1^3^3^4^5^4^5=1
*/