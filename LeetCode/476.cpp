#include <vector>
#include <iostream>
#include <bits/stdc++.h> 

using namespace std;

class Solution {
public:
    int findComplement(int num) {
        vector <int> bin;
        if (num==0)
        {
            return 1;
        }
        
        while (num >0)
        {
        bin.push_back(num%2);
        num/=2;
        }
        reverse(bin.begin(), bin.end());

        for (int i = 0; i < bin.size(); i++)
        {
            if (bin[i]==1)
            {
                bin[i]=0;
            }
            else
            {
                bin[i]=1;
            }
        }

        int ans=0;
        long long base=1;
        for (int i = bin.size()-1; i >=0; i--)
        {
            ans+=(base*bin[i]);
            base*=2;
        }
    return ans; 
    }
};