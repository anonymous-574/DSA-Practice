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

class NumberContainers {
    public:
        map<int,set<int>>number_to_index;
        map<int,int>index_to_num;
        NumberContainers() {
            
        }
        
        void change(int index, int number) {
            if (index_to_num.find(index)!=index_to_num.end()){
                int prev_num=index_to_num[index];
                number_to_index[prev_num].erase(index);

                if (number_to_index[prev_num].empty()){
                    number_to_index.erase(prev_num);
                }
            }
            number_to_index[number].insert(index);
            index_to_num[index]=number;
        }
        
        int find(int number) {
            if (!number_to_index[number].empty()){
                return *number_to_index[number].begin();
            }
            return -1;
        }

    };
    
    /**
     * Your NumberContainers object will be instantiated and called as such:
     * NumberContainers* obj = new NumberContainers();
     * obj->change(index,number);
     * int param_2 = obj->find(number);
     */