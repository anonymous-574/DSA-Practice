#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <iterator>
using namespace std;
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr)  {
    // The rank of each element is the number of UNIQUE elements smaller than it in the sorted array plus one

    //solution 1 (slow)
    /*
    vector <int> rank;
    vector <int> sorted = arr;
    sort(sorted.begin(), sorted.end());
    // use unique() to bring all the duplicates to end
    // and get the ierator for the modified vector
    auto it= unique(sorted.begin(), sorted.end());
    // Use erase method  to remove all the duplicates
    // from the vector
    sorted.erase(it, sorted.end());

    //slow
    
    int cnt=0;

    for (int i = 0; i < arr.size(); i++)
    {
        cnt=0;
    
    for (int j = 0; j < sorted.size(); j++)
    {
        if (sorted[j]==arr[i])
        {
            break;
        }
        cnt++;
    }
        rank.push_back(cnt+1);
    }
    
    */

    //default is ascending order for a set


    /*
    //solution 2 still slow .___.
    set<int> sorted;
    for (int i = 0; i < arr.size(); i++)
    {
        sorted.insert(arr[i]);
    }
    
    vector <int> rank;

    int cnt=0;
    vector<int>::iterator vector_iterator;
    // Initialize iterator and begin traversal
    for (vector_iterator = arr.begin(); vector_iterator != arr.end(); vector_iterator++) {
        cnt=distance(sorted.begin(), sorted.find(*vector_iterator));
        rank.push_back(cnt+1);
    }
    */

    vector <int> rank;
    map <int,int> val_to_rank;
    vector <int> sorted(arr);
    sort(sorted.begin(), sorted.end());

    int cnt=1;
    for (int i = 0; i < sorted.size(); i++)
    {
        if (i > 0 && sorted[i] > sorted[i - 1]) {
                cnt++;
            }
            val_to_rank[sorted[i]] = cnt;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        rank.push_back(val_to_rank[arr[i]]);
    }
    

    return rank; 
    }
};