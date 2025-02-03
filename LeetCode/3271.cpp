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
    string stringHash(string s, int k) {

        vector<string> hold;
        int temp = 0;
        string temp1;
        for (int i = 0; i < s.length(); i++) {
            temp1 += s[i];
            temp++;
            if (temp == k) {
                hold.push_back(temp1);
                temp = 0;
                temp1.clear();
            }
        }

        temp = 0;
        temp1.clear();
        for (int i = 0; i < hold.size(); i++) {
            for (int j = 0; j < hold[i].length(); j++) {
                temp += (int)hold[i][j] - 'a';
            }
            temp1 += (char)(temp % 26) + 'a';
            temp = 0;
        }

        return temp1;
    }
};

// good one

class Solution {
public:
    string stringHash(string s, int k) {
        string ans="";
        for(int i=0;i<s.size();i+=k)
        {
            int sum=0;
            for(int j=0;j<k;++j)
                sum+=s[i+j]-'a';
            sum=sum%26;
            ans+=(char)(sum+'a');
        }
        return ans;
    }
};