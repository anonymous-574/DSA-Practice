#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

class CustomStack {
public:

    int top=-1;
    int size=0;
    int * arr;
    CustomStack(int maxSize) {
        size=maxSize;
        arr = (int *) malloc (maxSize * sizeof(int));
    }
    
    bool is_empty()
    {
    if (top==-1)
    return true;
    
    return false;
    }

    bool is_full()
    {
    if (top ==(size-1))
    {return true;
    }

    return false;
    }

    void push(int x) {
        if (is_full())
    {return;}

    top++;
    arr[top]=x;
    }
    
    int pop() {
        if (is_empty())
    {
        return -1;
    }
    return arr[top--];
    }
    
    void increment(int k, int val) {
        if (k>top)
        {
            //increment all
            for (int i = 0; i <= top; i++)
            {
                arr[i]+=val;
            }
        }
        else
        {
            for (int i = 0; i <= k-1; i++)
            {
                arr[i]+=val;
            }
        }
        
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */