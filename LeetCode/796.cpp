#include <deque>
#include <iostream>
#include <algorithm>
#include <string> 
#include <queue>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {

        if (s.size()!=goal.size())
        {
            return false;
        }

        deque<char> s1(s.begin(),s.end());
        deque<char> g1(goal.begin(),goal.end());

        for (int i = 0; i < s.size(); i++)
        {
            s1.push_back(s1.front());
            s1.pop_front();
            if (s1==g1)
            {
                return true;
            }
            
        }
    return false;
    }
};