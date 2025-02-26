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

    string toBinary(int num, int bits) {
        return bitset<64>(num).to_string().substr(64 - bits);
    }

public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<int> temp;
        for (string i : nums) {
            temp.insert(stoi(i, nullptr, 2));
        }

        for (int i = 0; i < pow(2, nums[0].length()); i++) {
            if (temp.find(i) == temp.end()) {
                return toBinary(i, nums[0].length());
            }
        }
        return "";
    }
};


//1000000 IQ
class Solution {
    public:
        string findDifferentBinaryString(vector<string>& nums) {
            string ans;
            for (int i = 0; i < nums.size(); i++) {
                char curr = nums[i][i];
                ans += curr == '0' ? '1' : '0';
            }
            
            return ans;
        }
    };