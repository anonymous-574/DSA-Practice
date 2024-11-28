#include <vector>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

class MyCircularDeque {
public:
    
    int * arr;
    int f=0,r=0 ,size=0,temp=0;
    MyCircularDeque(int k) {
        size=k+1;
        arr=(int*) malloc(size* sizeof(int));
    }
    
    bool insertFront(int value) {
        if (isFull())
        {
            return false;
        }
       
        f--;
        f +=size;
        f %= size;
        arr[f] = value;
  
    return true;
    }
    
    bool insertLast(int value) {
        if (isFull())
        {
            return false;
        }
        r=r+1%size;
        arr[r]=value;
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty())
        {
            return false;
        }
        f=(f+1)%size;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty())
        {
            return false;
        }
        //r=(r-1)%size;
        r--;
        return true;
    }
    
    int getFront() {
        if (isEmpty())
        {
            return -1;
        }
        return arr[f];
    }
    
    int getRear() {
        if (isEmpty())
        {
            return -1;
        }
        return arr[r];
    }
    
    bool isEmpty() {
        if (f==r)
        {
            return true;
        }
        return false;
    }

    bool isFull() {
        if ( (r+1)%size ==f)
        {
            return true;
        }
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */