#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set <int> s;

        for (int i = 0; i < arr.size(); i++)
        {
            if ( (arr[i]%2==0 && s.find(arr[i]/2)!=s.end()) || s.find(arr[i]*2)!=s.end() )
            {
                return true;
            }
            else
            {
                s.insert(arr[i]);
            }
            
            
        }
        
        return false;
    }
};