#include <vector>
#include <iostream>
#include <bits/stdc++.h> 
#include <unordered_map>

using namespace std;

class Solution {
public: 
        bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length())
            return false;
        int s1arr [26];
        int s2arr [26];
        for (int i = 0; i < s1.length(); i++) {
            s1arr[char(s1[i]) - 'a']++;
            s2arr[char(s2[i]) - 'a']++;
        }
        for (int i = 0; i < s2.length() - s1.length(); i++) {
            if (matches(s1arr, s2arr))
                return true;
            s2arr[char(s2[i + s1.length()]) - 'a']++;
            s2arr[char(s2[i]) - 'a']--;
        }
        return matches(s1arr, s2arr);
    }
    
    bool matches(int * s1arr, int * s2arr) 
    {
        for (int i = 0; i < 26; i++) {
            if (s1arr[i] != s2arr[i])
                return false;
        }
        return true;
    }
};