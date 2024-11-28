#include <deque>
#include <iostream>
#include <algorithm>
#include <string> 
#include <queue>
#include <bits/stdc++.h>
using namespace std;
/*
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        vector <int> temp = piles;
        int range = *max_element(piles.begin(),piles.end());
        int k=0;
        int hours_elapsed=0;

        for (int i = 1; i < range; i++)
        {
            for (int j = 0; j < piles.size(); j++)
            {
               temp[j]/=i; 
               hours_elapsed++;
            }
            if (hours_elapsed>h)
            {
                hours_elapsed=0;
                continue;
            }
            
            if (accumulate(temp.begin(), temp.end(), 0)<=0)
            {
                k=i;
                break;
            }
            
            
            temp=piles;
        }
        
    return k; 
    }
};
*/

/*
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        vector <int> temp = piles;
        int range = *max_element(piles.begin(),piles.end());
        int k=0;
        int hours_elapsed=0;
        for (int i = 1; i < range; i++)
        {
            while (any_of(temp.begin(),temp.end(), [](int x) { return x > 0; }))
            {
                for(int j=0; j< piles.size();j++)
                {
                temp[j]-=i; 
                hours_elapsed++;
                }

                if (hours_elapsed>h)
                {
                hours_elapsed=0;
                temp=piles;
                break;
                }           
            }

            if (hours_elapsed>h)
            {continue;}
            
            k=i;
            break;
            if (accumulate(temp.begin(), temp.end(), 0)<=0)
            {
                k=i;
                break;
            }
                   
        }
        
    return k; 
    }
};
*/


class Solution {
public:
    int hours_elapsed=0;
    void eat (vector<int>& temp, int i)
    {
        for (int j = 0; j < temp.size(); j++)
        {
            temp[j]= round(temp[j]/i); 
            hours_elapsed++;
        }
    }
    int minEatingSpeed(vector<int>& piles, int h) {
    vector <int> temp = piles;
        int range = *max_element(piles.begin(),piles.end());
        int k=0;
        

        for (int i = 1; i < range; i++)
        {
            eat(temp,i);
            if (hours_elapsed>h)
            {
                hours_elapsed=0;
                continue;
            }
            
            if (accumulate(temp.begin(), temp.end(), 0)<=0)
            {
                k=i;
                break;
            }
            else
            {
                eat(temp,i);
            }
            temp=piles;
        }
        
    return k; 
    }
};