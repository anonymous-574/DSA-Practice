#include <iostream>
#include <algorithm>
#include <unordered_set> 
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkIfPangram(string sentence) {
    unordered_set<char> s(sentence.begin(),sentence.end());

    if(s.size()==26)
    {
        return true;
    }
    else
    {
        return false;
    }
    }
};