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
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;

        //sorting helps for larger data
        sort(words.begin(), words.end(),
             [](const std::string& a, const std::string& b) {
                 return a.length() < b.length();
             });

        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words.size(); j++) {
                if (i!=j && words[j].find(words[i]) != string::npos ) {
                    ans.push_back(words[i]);
                    break;
                }
            }
        }

        return ans;
    }
};