#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkString(string s) {
        
        int is_b=0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i]=='b')
            {
                is_b=1;
            }
            if (is_b==1 &&s[i]=='a')
            {
                return false;
            }
            
        }
        return true;

    }
};

int main() {
    // Your code starts here
    return 0;
}