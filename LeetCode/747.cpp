#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        auto it= max_element(nums.begin(), nums.end());
        int max = *it;
        nums.erase(it);
        int max2=*max_element(nums.begin(), nums.end());
        if(max2*2 > max)
        {
            return -1;
        }
        return distance(nums.begin(), it);
    }
};