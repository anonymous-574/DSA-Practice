#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        long long countSubarrays(vector<int>& nums, int k) {
            int max=*max_element(nums.begin(),nums.end());
            int start=0,end=0,count=0;
            long ans=0;
            for(end=0 ; end<nums.size(); end++){
                if (nums[end]==max){
                    count++;
                }

                while (count>=k){
                    if (nums[start]==max){
                    count--;
                    }
                    start++;
                }
                ans+=start;
            }
        return ans;   
        }
    };