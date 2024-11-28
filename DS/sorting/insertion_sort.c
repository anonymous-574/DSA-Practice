#include <stdio.h>

void print_arr(int *a,int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n\n");
}

void insertion_sort(int * a, int n)
{
    printf("Before Sorting: \n");
    print_arr(a,n);

    int key=0,j=0;

    for (int i = 1; i <= n-1; i++)
    {
        key=a[i];
        j=i-1;
        while (j>=0 && a[j]>key)
        {
            //keep on shifting
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
    

    printf("After Sorting : \n");
    print_arr(a,n);
}

int main(int argc, char const *argv[])
{
    int a[]={12,54,23,15,82,9};
    int n=6;
    insertion_sort(a,n);
    return 0;
}
