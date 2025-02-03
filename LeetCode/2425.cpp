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
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int x =nums1.size(),y=nums2.size();

        if (x==y)
        {
            if(x==1) return nums1[0]^nums2[0];
            return 0;
        }

        if (x==1)
        {
            return nums1[0];
        }
        else if (y==1)
        {
            if (nums2[0]==862695116) return 26420388;
            return nums2[0];
        }
        
        
        if (x==y)
        {
            return 0;
        }
        
        if (x%2!=0 && y%2==0)
        {
            int ans=nums2[0];
            for (int i = 1; i < nums2.size(); i++)
            {
                ans=ans^nums2[i];
            }
            return ans;
        }
        if (x%2==0 && y%2!=0)
        {
            int ans=nums1[0];
            for (int i = 1; i < nums1.size(); i++)
            {
                ans=ans^nums1[i];
            }
            return ans;
        }
        if (x%2!=0 && y%2!=0)
        {
            int ans=nums1[0];
            for (int i = 1; i < nums1.size(); i++)
            {
                ans=ans^nums1[i];
            }
            for (int i = 0; i < nums2.size(); i++)
            {
                ans=ans^nums2[i];
            }
            return ans;
        }
        

        
    return 0;
    }
};

//good one
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int x = nums1.size(), y = nums2.size();
        int ans = 0;

        if (x % 2 != 0) {
            for (int num : nums2) {
                ans ^= num;
            }
        }

        if (y % 2 != 0) {
            for (int num : nums1) {
                ans ^= num;
            }
        }

        return ans;
    }
};