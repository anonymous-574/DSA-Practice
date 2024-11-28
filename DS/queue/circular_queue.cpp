#include <iostream>
using namespace std;



//entire point of circular increment is
// instead of r++
//use r = (r+1) % size
class circular_queue
{
public:
       int f,r,size;
       int * arr;
    //constructor
    circular_queue(int size1)
    {
        size = size1;
        arr= (int *) malloc(size * sizeof(int));
    }
    bool is_full()
    {
        if ( (r+1)%size==f)
        {
            return true;
        }
        return false;
    }

    bool is_empty()
    {
        if (r==f)
        {
            return true;
        }
        return false;
    }

    void enqueue( int data)
    {
        if (is_full())
        {
            cout<<"FULL"<<endl;
            return;
        }
        r=(r+1)%size;
        arr[r]=data;
    }

    int dequeue()
    {
        if (is_empty())
        {
            cout<<"EMPTY"<<endl;
            return -1;
        }
        //increment front
        //so now the element before that becomes sacrificial
        //calculation for is_full changes
        f=(f+1)%size;
        return arr[f];
    }


};



int main(int argc, char const *argv[])
{
    circular_queue c(5);
    c.size=3;
    c.f=0;
    c.r=0;

    c.enqueue(5);
    c.enqueue(6);
    //c.enqueue(7);
    //c.enqueue(8);
    //c.enqueue(9);
    //c.enqueue(10);
    cout<<c.dequeue()<<endl;
    cout<<c.dequeue()<<endl;
    c.enqueue(5);
    c.enqueue(6);

    return 0;
}
