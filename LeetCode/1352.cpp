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

class ProductOfNumbers {
    public:
        vector<int> nums_prod;
        int temp = 0;
        ProductOfNumbers() {
            nums_prod.push_back(1);
            temp = 0;
        }
    
        void add(int num) {
            if (num == 0) {
                temp = 0;
                // the entire vector is changed
                nums_prod = {1};
            } else {
                nums_prod.push_back(nums_prod[temp] * num);
                temp++;
            }
        }
    
        int getProduct(int k) {
            if (k > temp) {
                return 0;
            }
            return nums_prod[temp] / nums_prod[temp - k];
        }
    };

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */