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
        int find_seq(vector<int> ch) {
            int tot = 0;
    
            for (int i = 0; i < 26; i++) {
                if (ch[i] == 0) {
                    continue;
                }
    
                tot++;
                ch[i]--;
                tot += find_seq(ch);
                ch[i]++;
            }
            return tot;
        }
    
        int numTilePossibilities(string tiles) {
            vector<int> ch(26, 0);
            for (char i : tiles) {
                ch[i - 'A']++;
            }
            return find_seq(ch);
        }
    };