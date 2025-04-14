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
        int numberOfAlternatingGroups(vector<int>& colors, int k) {
            int len=colors.size(),result=0,change_cnt=1;
                                    
        }
    };


/*
Algorithm

    Initialize:
        length to the size of the colors array.
        result to 0.
        alternatingElementsCount to 1, accounting for the first element of the array.
        lastColor to colors[0].
    Loop with i from 1 to length + k - 1 to wrap around to the first k - 1 elements:
        Set index to i % length.
        If colors[index] == lastColor, the pattern breaks:
            Reset the sequence length, i.e. set alternatingElementsCount to 1.
            Update lastColor to colors[index] and continue to the next element.
        Otherwise, colors[index] != lastColor, so the sequence can be extended:
        Increment alternatingElementsCount by 1.
        If alternatingElementsCount is greater than or equal to k, increment result by 1.
        Update lastColor to colors[index].
    Return result.


*/