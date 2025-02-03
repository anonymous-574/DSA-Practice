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
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>bef,aft,piv;
        for (int i: nums){
            if (i==pivot){
                piv.push_back(i);
            }
            else if (i>pivot){
                aft.push_back(i);
            }
            else{
                bef.push_back(i);
            }
        }

        bef.insert(bef.end(),piv.begin(),piv.end());
        bef.insert(bef.end(),aft.begin(),aft.end());
    return bef;
    }
};