#include <vector> 
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());

        //max length of streak is 5
        int max_len=0;
        int temp_len=0;
        long long curr=0;
        for (int i = 0; i < nums.size(); i++)
        {
            curr=nums[i];
            temp_len++;
            
            
            for (int i = 0; i <5; i++)
            {      
                if (s.find((int)curr) != s.end()) 
                {
                    temp_len++;
                    if (max_len<temp_len)
                    {
                        max_len=temp_len;
                    }
                    
                }
                else
                {
                    break;
                }
                if (curr * curr > 1e5) break;
                curr*=curr;
            }
            temp_len=0;
            
        }
    max_len--;
    if (max_len==0 || max_len==1)
    {
        return -1;
    }
    return max_len;
    }
};

