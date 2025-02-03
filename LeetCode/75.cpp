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

//hehe
class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(),nums.end());
    }
};

class Solution {
public:
    void sortColors(vector<int>& nums) {

        int z = 0, o = 0, t = 0;

        for (int i : nums) {
            switch (i) {
            case 0:
                z++;
                break;

            case 1:
                o++;
                break;

            case 2:
                t++;
                break;

            default:
                break;
            }
        }

        int i = 0;

        while (z > 0) {
            nums[i] = 0;
            i++;
            z--;
        }
        while (o > 0) {
            nums[i] = 1;
            i++;
            o--;
        }
        while (t > 0) {
            nums[i] = 2;
            i++;
            t--;
        }
    }
};