#include <iostream>
#include <vector>
#include <unordered_map> 
using namespace std;

    class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> remainderCount;

        // Store the count of remainders in a map.
        for (int i=0 ; i<arr.size(); i++)
        { 
            remainderCount[(i % k + k) % k]++;
        }

        for (int i=0 ; i<arr.size(); i++){
            int rem = (i % k + k) % k;

            // If the remainder for an element is 0, then the count
            // of numbers that give this remainder must be even.
            if (rem == 0) {
                if (remainderCount[rem] % 2 == 1) return false;
            }

            // If the remainder rem and k-rem do not have the
            // same count then pairs can not be made.
            else if (remainderCount[rem] != remainderCount[k - rem])
                return false;
        }
        return true;
    }
};