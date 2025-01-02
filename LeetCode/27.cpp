#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int start=0,end=nums.size()-1;

        while (end>start)
        {
            if (nums[start]==val)
            {
                swap(nums[start],nums[end]);
                end--;
            }
            start++;
        }
    return end;
    }
};