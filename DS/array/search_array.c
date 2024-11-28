#include <stdio.h>

int binary_search ( int arr[], int num , int size)
{
    int high , low , mid; // just indexes
    high = size-1;
    low = 0;
    while (high>=low)
    {
    mid = (low+high)/2;
    if (arr[mid]==num)
    {
        return mid;
    }
    else if (num>arr[mid])
    {
        low = mid+1;
    }
    else
    {
        high = mid -1;
    }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int location = binary_search(arr , 7 , (sizeof(arr)/sizeof(arr[0])));
    printf("location is %d ", location);
    return 0;
}