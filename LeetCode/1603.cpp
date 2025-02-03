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

class ParkingSystem { 
public:
    int park[3];
    ParkingSystem(int big, int medium, int small) {
        park[0]=big;
        park[1]=medium;
        park[2]=small;
    }
    
    bool addCar(int carType) {
        carType--;
        if (park[carType]>0){
            park[carType]--;
            return true;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */