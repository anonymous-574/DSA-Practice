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
    int countPalindromicSubsequence(string s) {
        unordered_set<char> letters;
        for (char c : s) {
            letters.insert(c);
        }
        
        int ans = 0;
        for (char letter : letters) {
            int i = -1;
            int j = 0;
            
            for (int k = 0; k < s.size(); k++) {
                if (s[k] == letter) {
                    if (i == -1) {
                        i = k;
                    }
                    
                    j = k;
                }
            }
            
            unordered_set<char> between;
            for (int k = i + 1; k < j; k++) {
                between.insert(s[k]);
            }
            
            ans += between.size();
        }
        
        return ans;
    }
};



/*
Read this task again. And notice that palindrome length is 3.
It consists of three chars only, the left, right character (first == last)
and the middle. The middle is only one character.
Think about spans rather than subsets. Consider any candidate that lies between spans but only one time.
Second hint: only 26 candidates are possible (only lowercase english letters).
*/