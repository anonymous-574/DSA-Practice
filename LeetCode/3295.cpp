#include <deque>
#include <iostream>
#include <algorithm>
#include <unordered_set> 
#include <queue>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_set<string> s(bannedWords.begin(),bannedWords.end());
        int cnt=0;

        for (int i = 0; i < message.size(); i++)
        {
            if (s.find(message[i])==s.end())
            {
                //not found
                continue;
            }
            else
            {
                cnt++;
                if(cnt>=2)
                {
                    return true;
                }
            }
            
        }
    return false;
    }
};