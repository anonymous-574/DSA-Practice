#include <vector>
#include <limits>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int size=nums.size();
        vector<int> dpi (size,1);

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i]>nums[j])
                {
                    dpi[i]=max(dpi[i],dpi[j]+1);
                }
            }
        }

        vector<int> dpd (size,1);

        for (int i = size-1; i >=0 ; i--)
        {
            for (int j = i+1; j < size; j++)
            {
                if (nums[i]>nums[j])
                {
                    dpd[i]=max(dpd[i],dpd[j]+1);
                }
            }
        }

        int min_r=INT_MAX;
        for (int i = 0; i < size; i++)
        {
            if (dpd[i]>1 && dpi[i]>1)
            {
                min_r=min(min_r, size+1-dpd[i]-dpi[i]);
            }
            
        }
        
    return min_r;
    }
};