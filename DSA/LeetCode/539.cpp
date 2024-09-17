#include <vector>
#include <iostream>
#include <bits/stdc++.h> 

using namespace std;

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        
        string hour , min;
        int temp=0;
        vector <int> time;

        for (int i =0 ; i<timePoints.size(); i++)
        {
            
            
            hour[0]=timePoints[i][0];
            hour[1]=timePoints[i][1];

            min[0]=timePoints[i][3];
            min[1]=timePoints[i][4];
            temp+=stoi(min);
            temp+=60*stoi(hour);
            time.push_back(temp);
            temp=0;
            min="";
            hour="";
        }

        sort(time.begin(), time.end()); 
        int time_diff =1000000;

        for (int i = 0; i < time.size()-1; i++)
        {
            temp = time[i+1]-time[i];
            if (temp<time_diff)
            {
                time_diff=temp;
            }        
        }

        temp= time[time.size()-1] -time[0];
        if (temp<time_diff)
            {
                time_diff=temp;
            }        
        
          
        return time_diff;
    }
};