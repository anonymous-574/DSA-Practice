#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
//curr is the index to heapify

void print(int * arr,int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n\n");
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int * arr, int n, int i, int isMinHeap) {
    int largest_smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (isMinHeap) {
        if (left < n && arr[left] < arr[largest_smallest])
            largest_smallest = left;
        if (right < n && arr[right] < arr[largest_smallest])
            largest_smallest = right;
    } else {
        if (left < n && arr[left] > arr[largest_smallest])
            largest_smallest = left;
        if (right < n && arr[right] > arr[largest_smallest])
            largest_smallest = right;
    }

    if (largest_smallest != i) {
        swap(&arr[i], &arr[largest_smallest]);
        heapify(arr, n, largest_smallest, isMinHeap);
    }
}

void heapSort(int * arr, int n, int isMinHeap) {
    //build heap from array
    for (int i = n / 2 - 1; i >= 0; i--){
        heapify(arr, n, i, isMinHeap);    
	} 
    printf("Heap Tree is: \n");
    print(arr,n);
    //swap it 
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0, isMinHeap);
        print(arr,n);
    } 
    printf("Sorted Array is: \n");
    print(arr,n);
}

void choice (int * arr,int size)
{
    int choice=0;
    printf("Welcome to choice \n Enter 1 to print \n Enter 2 to MaxHeap \n Enter 3 to MinHeap \n Enter 0 to end\n");
    int num=0,len=0;
    while (true)
    {
        printf("Enter choice \n");
        scanf("%d",&choice);
        if (choice==0)
        {
            printf("Goodbye");
            break;
        } 

        switch (choice)
        {
        case 2:
            printf("Performing MaxHeap: \n");
			heapSort(arr, size, 0);
            break;
        case 3:
            printf("Performing MinHeap: \n");
			heapSort(arr, size, 1);
            break;
        case 1:
            print(arr,size);
            break;
        default:
            printf("USER IS AN IDIOT! ");
            break;
        }
    }
}

int main(int argc, char const *argv[])
{
    
    int size=0;
    printf("Enter size of array: ");
    scanf("%d",&size);
    int * arr=(int *)malloc(size*sizeof(int));
    printf("Enter Elements: \n");
    int temp=0;
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&temp);
        arr[i]=temp;
    }
    choice(arr,size);

    free(arr);
    return 0;
}