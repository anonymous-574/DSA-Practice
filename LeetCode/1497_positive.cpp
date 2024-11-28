#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int pairs=0;
        int size=arr.size();
        for (int i = 0; i < size; i++)
        {
            //cout<<i<<endl;
            for (int j = i+1; j<size; j++)
            {
                //cout<<j<<endl;
                if ( ((arr[i]%k+arr[j]%k) +k) %k==0)
                {
                    cout<<arr[i]<<" I"<<endl;
                    cout<<arr[j]<<" J"<<endl;
                    cout<<"end"<<endl;
                    pairs++;
                }
                
            }
            
        }
        cout<<"Final ";
        cout<<pairs;
        if (pairs>=size/2)
        {
            return true;
        }
        return false;
    }
};