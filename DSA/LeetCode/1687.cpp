#include <string>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int total=0;
        int w_len=0 , cnt=0;
        for (int j=0 ; j< words.size() ; j++)
        {
            w_len=words[j].length();
            cnt=0;

            for ( int i =0 ; i<words[j].length(); i++)
            {
                if(allowed.find(words[j][i]) !=-1)
                {
                    cnt++;
                }
                else
                {
                    break;
                }

            }
            if (cnt==w_len)
            {
                total++;
            }
        }
        return total;
    }
};