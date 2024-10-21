#include <vector> 
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
 #include <numeric>
using namespace std;

class Solution {
public:
    int getLucky(string s, int k) {
        vector<int> digits;
        int mod=0;
        for (int i = 0; i < s.size(); i++)
        {
            int num = s[i]-'a'+1;
            while(num > 0) 
        {
            mod = num % 10;  
            digits.push_back(mod);
            num/= 10;    
        }
        }

        int sum=0;
        for (int i = 0; i <k; i++)
        {
            sum =accumulate(digits.begin(), digits.end(), 0);
            digits.erase(digits.begin(), digits.end());
            while(sum > 0) 
            {
                mod = sum % 10;  
                digits.push_back(mod);  
                sum/= 10;    
            }
        }
        digits.pop_back();
        int ans=0;
        int pow=1;
        //digits array has all the answer we need
        
        // WHY IS THIS WORKING
        for (int i = 0; i <=digits.size(); i++)
        {
            ans+=pow*digits[i];
            pow*=10;
            cout<<digits[i];
        }

    return ans;   
    }
};