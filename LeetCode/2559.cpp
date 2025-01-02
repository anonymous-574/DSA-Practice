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
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        // brite force is tle
        
        vector<int> ans(queries.size());
        unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};
        vector<int> prefixSum(words.size());
        int sum = 0;
        for (int i = 0; i < words.size(); i++) {
            string currentWord = words[i];
            if (vowels.count(currentWord[0]) &&
                vowels.count(currentWord[currentWord.size() - 1])) {
                sum++;
            }
            prefixSum[i] = sum;
        }

        for (int i = 0; i < queries.size(); i++) {
            vector<int> currentQuery = queries[i];
            ans[i] =
                prefixSum[currentQuery[1]] -
                (currentQuery[0] == 0 ? 0 : prefixSum[currentQuery[0] - 1]);
        }

        return ans;
    }
};

/*
Represent each word from words as 1 if it's vowel string and 0 if it's not.
You can do it as in additional aray as on a place as well;

Initialize first element of Prefix Sum array with 0 or 1, 
depending on is words[0] vowel string or not

Summarize arr[i] with arr[i - 1] as arr[i] = arr[i] + arr[i - 1] for all 1...n-1 indices.

To get a range by each query, if query starts from 0, it's arr[right], 
for all another cases it's arr[right] - arr[left - 1];
*/