#include <vector>
#include <iostream>
#include <bits/stdc++.h> 
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        unordered_map <char , int> s1_map;
        unordered_map <char , int> s2_map;

        for (int i = 0; i < 26; i++)
        {
            s1_map[char(i+97)]=0;
            s2_map[char(i+97)]=0;
        }

        //map for s1
        for (int i = 0; i < s1.size(); i++)
        {
            s1_map[s1[i]]++;   
        }
        
        /*
        for (int i = 0; i < s2.size(); i++)
        {
            if (s2_map[s2[i]]==0)
            {
                s2_map[s2[i]]++;
            }   
        }
        */

        //apply sliding window on s2

        int chk=0;
        for (int i = 0; i < s2.size(); i++)
        {
            for (int j = i; j< s1.size()+i && s1.size()+i <s2.size(); j++)
            {
                //set hashmap of s2 for same number of elements of s1
                s2_map[s2[j]]++;
                   
            }
            
            for (int i = 0; i < 26; i++)
            {
                if ( s2_map[char(i+97)]!=0 && s2_map[char(i+97)]==s1_map[char(i+97)])
                {
                    chk++;
                }
            }

            if(chk==s1.size())
            {
            return false;
            }

            for (int i = 0; i < 26; i++)
            {
            s2_map[char(i+97)]=0;
            }

        }

        return true;
        

    }
};

