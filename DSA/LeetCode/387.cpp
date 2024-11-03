#include <unordered_set>
#include <iostream>
#include <algorithm>
#include <string> 
#include <queue>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_set <char> s1;

        for (int i = 0; i < s.size(); i++)
        {
            if (s1.find(s[i]) != s1.end() && !s1.empty()) { 
            //found
            s1.erase(s[i]);
            }
            else
            {
                s1.insert(s[i]);
            }
            
        }
    return *s1.begin(s1.size()-1);
    }
};