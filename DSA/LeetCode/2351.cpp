#include <unordered_set>
#include <iostream>
#include <algorithm>
#include <string> 
#include <queue>
using namespace std;

class Solution {
public:
    char repeatedCharacter(string s) {
      unordered_set <char> s1;
      char ans;
      for (int i = 0; i < s.size(); i++)
      {
        if (s1.find(s[i]) != s1.end()) { 
            //found
            ans=s[i];
            break;
        }
        else
        {
            s1.insert(s[i]);
        }
        
      }
    return ans;
    }
};