#include <vector> 
#include <iostream>
#include <bits/stdc++.h>
#include <unordered_set> 

using namespace std;
    
class Solution {
public:

    int countWords(vector<string>& words1, vector<string>& words2) {
    unordered_set<string> set_word;
    unordered_set<string> set_c;

        for (int i = 0; i < words1.size(); i++)
        {
            if (set_word.find(words1[i]) == set_word.end())
            {
                set_word.insert(words1[i]);
            }
        }

        for (int i = 0; i < words2.size(); i++)
        {
            /*
            if (set_word.find(words2[i]) == set_word.end() && set_c.find(words2[i]) != set_c.end())
            {
                set_word.insert(words2[i]);
            }
            else
            {
                set_c.insert(words2[i]);
            }
            */
            if (set_word.find(words2[i]) == set_word.end())
            {
                //no copy
                continue;;
            }
            else
            {
                set_c.insert(words2[i]);
            }
        }

        return set_c.size();
    }
};