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
    int countCollisions(string directions) {
        stack<char> hold;

        int ans = 0;
        for (int i = 0; i < directions.size(); i++) {
            if (hold.empty()) {
                hold.push(directions[i]);
            } else {
                if (hold.top() == directions[i]) {
                    hold.push(directions[i]);
                } else if (hold.top() == 'L' && directions[i] == 'R') {
                    hold.push(directions[i]);
                } else if (hold.top() == 'R' && directions[i] == 'L') {
                    ans += 2;
                    hold.top()='S';
                } else if (hold.top() == 'R' && directions[i] == 'S') {
                    ans++;
                    hold.top()='S';
                } else if (hold.top() == 'S' && directions[i] == 'L') {
                    ans++;
                }
                else
                {
                    hold.push(directions[i]);
                }
                cout<<directions[i]<<" "<<ans<<endl;
            }
        }

        return ans;
    }
};


//DONT OVERCOMPLICATE
class Solution {
public:
    int countCollisions(string directions) {
        int i=0,j=directions.length()-1;
        while (directions[i]=='L'){
            i++;
        }
        while (directions[j]=='R'){
            j--;
        }
        
        int ans=0;
        while (i!=j){
            if (directions[i]!='S'){
                ans++;
            }
            i++;
            j--;
        }
        
        
    return ans;
    }
};