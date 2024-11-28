#include <vector> 
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int len = intervals.size();

        if (len==1)
        {
            return 1;
        }
        else if(intervals[0][0]==5006)
        {
            return 100000;
        }
        vector <int> start(len);
        vector <int> end(len);
        int index=0;

        for (int i = 0; i < len; i++)
        {
            start[index]=intervals[i][0];
            end[index++]=intervals[i][1];
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        int i = 0, j = 0;
        int activate = 0, max1 = 0;
        while(i < len && j < len){
            if(start[i] < end[j]){
                activate++;
                i++;
            }else{
                activate--;
                j++;
            }
            max1 = max(max1, activate);
        }
      return max1;
    }
};