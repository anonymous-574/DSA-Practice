#include <stdio.h>

void ptr_insert(int* arr, int index , int value, int used_size, int capacity)
{
    if (used_size>=capacity)
    {
        return; 
    }
    for (int i = used_size-1; i >=index; i--)
    {
        *(arr+i+1)=*(arr+i);
    }
    *(arr+index)= value;
    return;
}

void ptr_del(int* arr, int index , int used_size, int capacity)
{
    if (used_size>=capacity)
    {
        return; 
    }
    for (int i = index; i <used_size; i++)
    {
        *(arr+i)=*(arr+i+1);
    }
    return;
}

void print(int arr[] , int used_size)
{
    for (int i = 0; i < used_size; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return;
}


int main(int argc, char const *argv[])
{
    int arr[10]={1,5,3,2,4,5};
    int* ptr = arr;
    int size = 6;
    int capacity = 10;
    ptr_insert(ptr , 3,88,size,capacity);
    size++;
    print(arr , size);
    ptr_del(ptr,3,size,capacity);
    size--;
    print(arr,size);
    return 0;
}