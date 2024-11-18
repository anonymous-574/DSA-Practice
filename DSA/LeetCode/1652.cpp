#include <deque>
#include <iostream>
#include <algorithm>
#include <string> 
#include <queue>
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int size = code.size();
        vector <int> arr (size,0);
        if (k==0)
        {
            return arr;
        }
        int k_size=abs(k);
        int temp_cnt=0;
        int temsum=0;
        for (int i = 0; i <size; i++)
        {
            if (k>0)
            {
                for (int j = i+1; ; j++)
                {
                    temsum+=code[j%size];
                    temp_cnt++;
                    if (temp_cnt>=k_size)
                    {
                        break;
                    }
                }
                arr[i]=temsum;
                temsum=0;
                temp_cnt=0;
            }
            else
            {
                for (int j = i-1; ; j--)
                {
                    if (j<0)
                    {
                        j=size-1;
                    }
                    temsum+=code[j];
                    temp_cnt++;
                    if (temp_cnt>=k_size)
                    {
                        break;
                    }
                }
                arr[i]=temsum;
                temsum=0;
                temp_cnt=0;
            }
        }
    return arr;
    }
};