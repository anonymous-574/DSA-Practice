#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <map>
#include <iterator>
using namespace std;

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set <int> s(nums.begin(),nums.end());

        while (true)
        {
            if (s.find(original)!=s.end())
            {
                original*=2;
            }
            else
            {
                return original;
            }      
        }

    }
};