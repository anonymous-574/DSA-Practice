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
    int trap(vector<int>& height) {
        int size=height.size();
        vector<int> ml(size),mr(size);
        ml[0]=0;
        mr[size-1]=0;


        for (int i = 1; i < size; i++)
        {
            ml[i]=max(height[i],height[i-1]);
        }

        for (int i = size-2; i >=0 ; i--)
        {
            mr[i]=max(height[i],height[i+1]);
        }

        int ans=0;
        int temp;
        for (int i = 0; i < size; i++){
            temp=min(ml[i],mr[i])-height[i];
            if (temp>=0){
                ans==temp;
            }
        }
        
    return ans;
    }
};