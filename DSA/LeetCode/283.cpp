#include <vector>
#include <iostream>
#include <bits/stdc++.h> 

using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       int snowBallSize = 0; 
       int t=0;
        for (int i=0;i<nums.size();i++){
	        if (nums[i]==0){
                snowBallSize++; 
            }
            else if (snowBallSize > 0) {
	            t = nums[i];
	            nums[i]=0;
	            nums[i-snowBallSize]=t;
            }
        }
    }
};