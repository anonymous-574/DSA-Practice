#include <vector> 
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long size = skill.size();
        if (size==2)
        {
            return skill[0]*skill[1];
        }
        
        sort(skill.begin(), skill.end()); 

        int start=0, end = size-1;
        vector <vector<int>> arr;
        vector <int> temp;
        long size_to=size/2;
        while (true && arr.size()<=size_to-1)
        //while (true)
        {
            temp.push_back(skill[start]);
            temp.push_back(skill[end]);
            arr.push_back(temp);
            temp.clear();
            start++;
            end--;
            if(start==end)
            {
                break;
            }
        }
        int num1=arr[0][0];
        int num2=arr[0][1];
        long sum=num1+num2;
        long long ans=num1*num2;
        for (int i = 1; i < size_to; i++)
        {
            num1=arr[i][0];
            num2=arr[i][1];
            ans+=num1*num2;

            if (sum!=num1+num2)
            {
                return -1; 
            }
             
        }
        return ans;
        
    }
};