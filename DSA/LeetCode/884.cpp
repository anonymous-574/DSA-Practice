#include <vector> 
#include <iostream>
#include <bits/stdc++.h>
#include <sstream>
using namespace std;
    
class Solution {
public:
    vector<string> split_sentence(string sen) {
    stringstream ss(sen);
    string word;
    vector<string> words;
    while (ss >> word) {
        words.push_back(word);
    }
    return words;
    }


    vector<string> uncommonFromSentences(string s1, string s2) {
    vector <string> words1= split_sentence(s1);
    vector <string> words2 = split_sentence(s2);
    unordered_set<string> set_unc;
    unordered_set<string> set_c;
    vector <string> ans;

        for (int i = 0; i < words1.size(); i++)
        {
            if (set_unc.find(words1[i]) == set_unc.end() && set_c.find(words1[i]) == set_c.end())
            {
                set_unc.insert(words1[i]);
            }
            else
            {
                set_c.insert(words1[i]);
                set_unc.erase(words1[i]);
            }
            
        }

        for (int i = 0; i < words2.size(); i++)
        {
             if (set_unc.find(words2[i]) == set_unc.end() && set_c.find(words2[i]) == set_c.end() )
            {
                set_unc.insert(words2[i]);
            }
            else
            {
                set_c.insert(words2[i]);
                set_unc.erase(words2[i]);
            }
            
        }

        unordered_set<string>::iterator itr;
        for (itr = set_unc.begin(); itr != set_unc.end();itr++)
        ans.push_back(*itr);
        return ans;
    }
};