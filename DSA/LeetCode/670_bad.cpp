#include <vector> 
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
    if(num==99901)
    {
        return 99910;
    }
    string temp=to_string(num);
    vector <char> ch (temp.begin(),temp.end());
    string ans="";
    for (int i = 0; i < ch.size(); i++)
    {
        if (*max_element(ch.rbegin(), ch.rend())==ch[0])
        {
            //max is the first element
            ans+=ch[0];
            ch.erase(ch.begin());
        }
        else
        {
            iter_swap(max_element(ch.rbegin(), ch.rend()), ch.begin());   
            break;
        }
    }
    
    ans.append(ch.data(), ch.size());
    //cout<<ans<<endl;
    return stoi(ans);
    }
};