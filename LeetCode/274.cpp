#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <limits>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
            int n=citations.size();
            int idx=0;
            for (int i = 0; i < n; i++){
                if (n-i<=citations[i]){
                    return n-i;
                }
            }
            return 0;
              
    }
};

/*
class Solution {
public:
    int hIndex(vector<int>& citations) {

        

        sort(citations.begin(),citations.end());

        //right sides indexes is size - index

        // Remove duplicates
        auto it = std::unique(citations.begin(), citations.end());
        citations.erase(it, citations.end());
        cout<<citations.size()<<endl;
        int idx=0;
        for (int i = 0; i < citations.size(); i++)
        {
            if (citations.size()-i >= idx)
            {
                idx++;
                cout<<i<<idx<<endl;
            }
            else
            {
                break;
            }
            
        }
        return idx;
    }
};

*/



class Solution {
public:
    int hIndex(vector<int>& citations) {

        if(citations[0]==0)
        {
            return 0;
        }

        sort(citations.begin(),citations.end());

        //right sides indexes is size - index

        // Remove duplicates
        auto it = unique(citations.begin(), citations.end());
        int idx=0;
        if (it != citations.end()) {
            cout<<"duplicate";
            citations.erase(it, citations.end());
            for (int i = 0; i < citations.size(); i++){
            if (citations.size()-i >= idx){
                idx++;
                cout<<i<<idx<<endl;
            }
            else{
                break;
            }
            
        }
            return idx-1;
        }
        else
        {
            for (int i = 0; i < citations.size(); i++)
            {
            if (citations.size()-i >= idx)
            {
                idx++;
                cout<<i<<idx<<endl;
            }
            else
            {
                break;
            }
            
            }
        return idx;
        }        
    }
};
