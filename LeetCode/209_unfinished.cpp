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

// greedy fails
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {

        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum < target)
        {
            return 0;
        }

        int size = nums.size();
        int start = 0;
        int end = size - 1;
        while (true)
        {
            if (nums[start] > nums[end])
            {
                // kill the end
                // first check

                if (sum - nums[end] < target)
                {
                    break;
                }

                sum -= nums[end];
                end--;
                size--;
            }
            else
            {
                if (sum - nums[start] < target)
                {
                    break;
                }
                sum -= nums[start];
                start++;
                size--;
            }
        }

        return size;
    }
};

