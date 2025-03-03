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

//Beats 100% , one pass
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans(nums.size());
        int lessI = 0;
        int greaterI = nums.size() - 1;
        for (int i = 0, j = nums.size() - 1; i < nums.size(); i++, j--) {
            if (nums[i] < pivot) {
                ans[lessI] = nums[i];
                lessI++;
            }
            if (nums[j] > pivot) {
                ans[greaterI] = nums[j];
                greaterI--;
            }
        }
        while (lessI <= greaterI) {
            ans[lessI] = pivot;
            lessI++;
        }
        return ans;
    }
};