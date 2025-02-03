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
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
        vector<string> ans;

        vector<int> maxcount(26,0);
        
        for (const auto& word : words2) {
            int count[26] = {0}; 
            for (char ch : word) {
                count[ch - 'a']++;
            }

            for (int i = 0; i < 26; ++i) {
                maxcount[i] = max(maxcount[i], count[i]);
            }
        }

        for (int i = 0; i < words1.size(); i++)
        {
            int count[26] = {0};
            for (int j = 0; j < words1[i].length(); j++)
            {
                count[words1[i][j]-'a']++;
                
            }

            bool isUniversal = true;
            for (int i = 0; i < 26; ++i) {
                if (count[i] < maxcount[i]) {
                    isUniversal = false;
                    break;
                }
            }

            if (isUniversal) {
                ans.push_back(words1[i]);
            }
            
        }
        
    return ans;
    }
};