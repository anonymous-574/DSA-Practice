#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector <int> bits(24,0);

        for (int i = 0; i < 24; i++)
        {
            for (int j = 0; j < candidates.size(); j++)
            {
            if ( (candidates[j] & (1 << i)) != 0)
            {
                bits[i]++;
            }
            }
        }
    return *max_element(bits.begin(),bits.end());
    }
};