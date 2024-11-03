#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//curr is the index to heapify 
void max_heapify(int * arr,int size,int curr)
{
    int left=2*curr+1 , right=2*curr+2;
    int largest=curr;
    //if there is a ledt child and if the left child is greater than current
    if (left<=size && arr[left]>arr[largest])
    {
        largest=left;
    }
    
    if (right<=size && arr[right]>arr[largest])
    {
        largest=right;
    }

    int temp=0;
    if (largest!=curr)
    {
        temp=arr[curr];
        arr[curr]=arr[largest];
        arr[largest]=temp;
        max_heapify(arr,size,largest);
    }
    
}

void min_heapify(int *arr, int size, int curr)
{
    int left = 2 * curr + 1;
    int right = 2 * curr + 2;
    int smallest=curr;

    // If there is a left child and the left child is smaller than the current node
    if (left <= size && arr[left] < arr[smallest])
    {
        smallest = left;
    }
    // If there is a right child and the right child is smaller than the smallest so far
    if (right <= size && arr[right] < arr[smallest])
    {
        smallest = right;
    }

    int temp = 0;
    // If the smallest is not the current node, swap and continue heapifying
    if (smallest != curr)
    {
        temp = arr[curr];
        arr[curr] = arr[smallest];
        arr[smallest] = temp;
        min_heapify(arr, size, smallest);
    }
}

void min_heap(int * arr,int size)
{
    for (int i = size/2 -1; i >=0; i--)
    {
        min_heapify(arr,size,i);
    }
    
}

void max_heap(int * arr,int size)
{
    for (int i = ceil(size/2)-1; i >=0; i--)
    {
        max_heapify(arr,size,i);
    }
    
}

void print(int * arr,int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n\n");
}

int main(int argc, char const *argv[])
{
    
    int size=5;

    //printf("Enter size of array");
    //scanf("%d",&size);
    //int * arr=(int *)malloc(size*sizeof(int));
    /*
    for (int i = 0; i < size; i++)
    {
        scanf("%d",arr[i]);
    }
    */
    //int arr [5]={5,1,4,2,6};
    int arr [5]={5,1,8,2,6};  //????????????????
    //max_heap(arr,size);
    //print(arr,size);
    min_heap(arr,size);
    print(arr,size);

    //free(arr);
    return 0;
}
