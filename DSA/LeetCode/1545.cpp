#include <iostream>
#include <vector>
#include <unordered_map> 
#include <bits/stdc++.h>
#include <algorithm>
#include <string>
using namespace std;

/*
class Solution {
public:

    string invert_str(string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i]=='0')
        {
            s[i]='1';
        }
        else
        {
            s[i]='0';
        }
    }
    return s;
}
    char findKthBit(int n, int k) {

    vector <string> s(21);
    s[0]="0";
    string to_rev;
    for (int i = 1; i <= 20; i++)
    {
        to_rev=invert_str(s[i-1]);
        string reversed(to_rev.rbegin(), to_rev.rend());
        s[i]=s[i-1]+"1" + reversed;
    }
    return s[n][k];
    }
};
*/



class Solution {
public:
    char findKthBit(int n, int k) {
        // Base case: When n = 1, the binary string is "0"
        if (n == 1) return '0';
        
        // Find the length of the current string Sn, which is 2^n - 1
        int length = (1 << n) - 1;
        
        // Find the middle position
        int mid = length / 2 + 1;
        
        // If k is the middle position, return '1'
        if (k == mid) return '1';
        
        // If k is in the first half, find the bit in Sn-1
        if (k < mid) return findKthBit(n - 1, k);
        
        // If k is in the second half, find the bit in Sn-1 and invert it
        return findKthBit(n - 1, length - k + 1) == '0' ? '1' : '0';
    }
};

